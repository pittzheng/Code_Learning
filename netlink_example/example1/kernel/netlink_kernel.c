#include <linux/module.h>
#include <linux/kernel.h>
#include <net/netlink.h>
#include <net/net_namespace.h>

#define MYPROTO NETLINK_USERSOCK
#define MYGRP 22

static struct sock *nl_sk;
static struct timer_list timer;

void try_send(unsigned long data)
{
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    char *msg = "Hello from kernel";
    int msg_size = strlen(msg) + 1;
    int res;

    skb = nlmsg_new(NLMSG_ALIGN(msg_size + 1), GFP_ATOMIC);
    if (!skb) {
        pr_err("Allocation failure.\n");
        return;
    }

    nlh = nlmsg_put(skb, 0, 1, NLMSG_DONE, msg_size + 1, 0);
    strcpy(nlmsg_data(nlh), msg);

    pr_info("Sending multicast.\n");
    res = nlmsg_multicast(nl_sk, skb, 0, MYGRP, GFP_ATOMIC);
    if (res < 0) {
        pr_info("nlmsg_multicast() error: %d. Will try again later.\n", res);
        /* Wait 1 second. */
        mod_timer(&timer, jiffies + msecs_to_jiffies(1000));
    } else {
        pr_info("Success.\n");
    }
}

static int handle_netlink_message(struct sk_buff *skb_in, struct nlmsghdr *nl_hdr)
{
    char *hello;
    hello = NLMSG_DATA(nl_hdr);
    pr_info("Userspace says '%s.'\n", hello);
    return 0;
}

static void receive_answer(struct sk_buff *skb)
{
    netlink_rcv_skb(skb, &handle_netlink_message);
}

static int __init hello_init(void)
{
    struct netlink_kernel_cfg cfg =
    {
        .input = receive_answer,
    };
    pr_info("Inserting module.\n");
    nl_sk = netlink_kernel_create(&init_net, MYPROTO, &cfg);
    if (!nl_sk) {
        pr_err("Error creating socket.\n");
        return -10;
    }

    init_timer(&timer);
    timer.function = try_send;
    timer.expires = jiffies + 1000;
    timer.data = 0;
    add_timer(&timer);

    return 0;
}

static void __exit hello_exit(void)
{
    del_timer_sync(&timer);
    netlink_kernel_release(nl_sk);
    pr_info("Exiting module.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
