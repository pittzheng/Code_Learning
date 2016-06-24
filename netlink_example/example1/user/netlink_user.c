#include <netlink/netlink.h>
#include <netlink/msg.h>

#define MYPROTO NETLINK_USERSOCK
#define MYMGRP 22

struct nl_sock *sk;

void respond_to_kernel(void)
{
    char *response = "foo bar";
    int error;

    error = nl_send_simple(sk, 12345, NLMSG_DONE, response, strlen(response) + 1);
    if (error < 0) {
        printf("nl_send_simple() threw errcode %d.\n", error);
        printf("libnl's message: %s", nl_geterror(error));
    } else {
        printf("Responded %d bytes.\n", error);
    }
}

int receive_kernel_request(struct nl_msg *msg, void *arg)
{
    char *hello;

    hello = nlmsg_data(nlmsg_hdr(msg));
    printf("Kernel says '%s'.\n", hello);
    respond_to_kernel();

    return 0;
}

int prepare_socket(void)
{
    int error;

    sk = nl_socket_alloc();
    if (!sk) {
        printf("nl_socket_alloc() returned NULL.\n");
        return -1;
    }

    nl_socket_disable_seq_check(sk);

    error = nl_socket_modify_cb(sk, NL_CB_FINISH, NL_CB_CUSTOM, receive_kernel_request, NULL);
    if (error < 0) {
        printf("Could not register callback function. Errcode: %d\n", error);
        goto fail;
    }

    error = nl_connect(sk, MYPROTO);
    if (error < 0) {
        printf("Connection failed: %d\n", error);
        goto fail;
    }

    error = nl_socket_add_memberships(sk, MYMGRP, 0);
    if (error) {
        printf("Could not register to the multicast group. %d\n", error);
        goto fail;
    }

    return 0;

fail:
    printf("libnl's message: %s\n", nl_geterror(error));
    nl_socket_free(sk);
    return error;
}

int wait_for_kernel_message(void)
{
    int error;

    printf("Waiting for kernel request...\n");
    error = nl_recvmsgs_default(sk);
    if (error < 0) {
        printf("nl_send_simple() threw errcode %d.\n", error);
        printf("libnl's message: %s\n", nl_geterror(error));
        return error;
    }

    return 0;
}

void destroy_socket(void)
{
    nl_socket_free(sk);
}

int main(int argc, char *argv[])
{
    int error;

    error = prepare_socket();
    if (error)
        return error;

    error = wait_for_kernel_message();
    destroy_socket();
    return error;
}
