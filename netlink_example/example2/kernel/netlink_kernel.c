#include <linux/kernel.h>
#include <linux/module.h>
#include <net/genetlink.h>

static struct timer_list timer;

/* Code based on http://stackoverflow.com/questions/26265453/netlink-multicast-kernel-group/33578010#33578010 */    
/**
 * This callback runs whenever the socket receives messages.
 * We don't use it now, but Linux complains if we don't define it.
 */
static int hello(struct sk_buff *skb, struct genl_info *info)
{
        pr_info("Received a message in kernelspace.\n");
        return 0;
}

/**
 * Attributes are fields of data your messages will contain.
 * The designers of Netlink really want you to use these instead of just dumping
 * data to the packet payload... and I have really mixed feelings about it.
 */
enum attributes {
        /*
         * The first one has to be a throwaway empty attribute; I don't know
         * why.
         * If you remove it, ATTR_HELLO (the first one) stops working, because
         * it then becomes the throwaway.
         */
        ATTR_DUMMY,
        ATTR_HELLO,
        ATTR_FOO,

        /* This must be last! */
        __ATTR_MAX,
};

/**
 * Here you can define some constraints for the attributes so Linux will
 * validate them for you.
 */
static struct nla_policy policies[] = {
                [ATTR_HELLO] = { .type = NLA_STRING, },
                [ATTR_FOO] = { .type = NLA_U32, },
};

/**
 * Message type codes. All you need is a hello sorta function, so that's what
 * I'm defining.
 */
enum commands {
        COMMAND_HELLO,

        /* This must be last! */
        __COMMAND_MAX,
};

/**
 * Actual message type definition.
 */
struct genl_ops ops[] = {
        {
                .cmd = COMMAND_HELLO,
                .flags = 0,
                .policy = policies,
                .doit = hello,
                .dumpit = NULL,
        },
};

/**
 * A Generic Netlink family is a group of listeners who can and want to speak
 * your language.
 * Anyone who wants to hear your messages needs to register to the same family
 * as you.
 */
struct genl_family family = {
                .id = GENL_ID_GENERATE,
                .hdrsize = 0,
                .name = "PotatoFamily",
                .version = 1,
                .maxattr = __ATTR_MAX,
};

/**
 * And more specifically, anyone who wants to hear messages you throw at
 * specific multicast groups need to register themselves to the same multicast
 * group, too.
 */
struct genl_multicast_group groups[] = {
        { .name = "PotatoGroup" },
};

void send_multicast(unsigned long arg)
{
        struct sk_buff *skb;
        void *msg_head;
        unsigned char *msg = "TEST";
        int error;

        pr_info("----- Running timer -----\n");

        pr_info("Newing message.\n");
        skb = genlmsg_new(NLMSG_GOODSIZE, GFP_KERNEL);
        if (!skb) {
                pr_err("genlmsg_new() failed.\n");
                goto end;
        }

        pr_info("Putting message.\n");
        msg_head = genlmsg_put(skb, 0, 0, &family, 0, COMMAND_HELLO);
        if (!msg_head) {
                pr_err("genlmsg_put() failed.\n");
                kfree_skb(skb);
                goto end;
        }

        pr_info("Nla_putting string.\n");
        error = nla_put_string(skb, ATTR_HELLO, msg);
        if (error) {
                pr_err("nla_put_string() failed: %d\n", error);
                kfree_skb(skb);
                goto end;
        }

        pr_info("Nla_putting integer.\n");
        error = nla_put_u32(skb, ATTR_FOO, 12345);
        if (error) {
                pr_err("nla_put_u32() failed: %d\n", error);
                kfree_skb(skb);
                goto end;
        }

        pr_info("Ending message.\n");
        genlmsg_end(skb, msg_head);

        pr_info("Multicasting message.\n");
        /*
         * The family has only one group, so the group ID is just the family's
         * group offset.
         * mcgrp_offset is supposed to be private, so use this value for debug
         * purposes only.
         */
        pr_info("The group ID is %u.\n", family.mcgrp_offset);
        error = genlmsg_multicast_allns(&family, skb, 0, 0, GFP_KERNEL);
        if (error) {
                pr_err("genlmsg_multicast_allns() failed: %d, %d\n", error, ESRCH);
                pr_err("(This can happen if nobody is listening. "
                                "Because it's not that unexpected, "
                                "you might want to just ignore this error.)\n");
                goto end;
        }

        pr_info("Success.\n");
end:
        mod_timer(&timer, jiffies + msecs_to_jiffies(2000));
}

static int init_socket(void)
{
        int error;

        pr_info("Registering family.\n");
        error = genl_register_family_with_ops_groups(&family, ops, groups);
        if (error)
                pr_err("Family registration failed: %d\n", error);

        return error;
}

static void initialize_timer(void)
{
        pr_info("Starting timer.\n");

        init_timer(&timer);
        timer.function = send_multicast;
        timer.expires = 0;
        timer.data = 0;

        mod_timer(&timer, jiffies + msecs_to_jiffies(2000));
}

static int __init hello_init(void)
{
        int error;

        error = init_socket();
        if (error)
                return error;

        initialize_timer();

        pr_info("Hello module registered.\n");
        return 0;
}

static void __exit hello_exit(void)
{
        del_timer_sync(&timer);
        genl_unregister_family(&family);
        pr_info("Hello removed.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
