#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>

#include <linux/genetlink.h>

/* Code based on libnl-3 */
/* Code based on http://stackoverflow.com/questions/26265453/netlink-multicast-kernel-group/33578010#33578010 */
/* Code based on http://www.electronicsfaq.com/2014/02/generic-netlink-sockets-example-code.html */
/* Code based on http://people.ee.ethz.ch/~arkeller/linux/multi/kernel_user_space_howto-3.html */


/* Based on libnl-3 attr.h */
/**
 * @ingroup attr
 * Basic attribute data types
 *
 * See section @core_doc{core_attr_parse,Attribute Parsing} for more details.
 */
enum {
    NLA_UNSPEC, /**< Unspecified type, binary data chunk */
    NLA_U8,     /**< 8 bit integer */
    NLA_U16,    /**< 16 bit integer */
    NLA_U32,    /**< 32 bit integer */
    NLA_U64,    /**< 64 bit integer */
    NLA_STRING, /**< NUL terminated character string */
    NLA_FLAG,   /**< Flag */
    NLA_MSECS,  /**< Micro seconds (64bit) */
    NLA_NESTED, /**< Nested attributes */
    NLA_NESTED_COMPAT,
    NLA_NUL_STRING,
    NLA_BINARY,
    NLA_S8,
    NLA_S16,
    NLA_S32,
    NLA_S64,
    __NLA_TYPE_MAX,
};

#define NLA_TYPE_MAX (__NLA_TYPE_MAX - 1)

/**
 * @ingroup attr
 * Attribute validation policy.
 *
 * See section @core_doc{core_attr_parse,Attribute Parsing} for more details.
 */
struct nla_policy {
    /** Type of attribute or NLA_UNSPEC */
    uint16_t    type;

    /** Minimal length of payload required */
    uint16_t    minlen;

    /** Maximal length of payload allowed */
    uint16_t    maxlen;
};


/**
 * Attributes and commands have to be the same as in kernelspace, so you might
 * want to move these enums to a .h and just #include that from both files.
 */
enum attributes {
        ATTR_DUMMY,
        ATTR_HELLO,
        ATTR_FOO,

        /* This must be last! */
        __ATTR_MAX,
};

enum commands {
        COMMAND_HELLO,

        /* This must be last! */
        __COMMAND_MAX,
};

/* Generic macros for dealing with netlink sockets. Might be duplicated
 * elsewhere. It is recommended that commercial grade applications use
 * libnl or libnetlink and use the interfaces provided by the library
 */
#define GENLMSG_DATA(glh) ((void *)(NLMSG_DATA(glh) + GENL_HDRLEN))
#define GENLMSG_PAYLOAD(glh) (NLMSG_PAYLOAD(glh, 0) - GENL_HDRLEN)
#define NLA_DATA(na) ((void *)((char*)(na) + NLA_HDRLEN))

/* Family string */
#define GEN_FAMILY_STR  "PotatoFamily"
#define GEN_ML_GRP_STR  "PotatoGroup"

/* SOL_NETLINK is only defined in <kernel src>/include/linux/socket.h
 * It is not defined in <kernel src>/include/uapi/linux/socket.h
 * Thus, copy the define to here if we don't include kernel header
 */
#ifndef SOL_NETLINK
#define SOL_NETLINK 270
#endif

/**
 * @ingroup attr
 * Iterate over a stream of attributes
 * @arg pos loop counter, set to current attribute
 * @arg head    head of attribute stream
 * @arg len length of attribute stream
 * @arg rem initialized to len, holds bytes currently remaining in stream
 */
#define nla_for_each_attr(pos, head, len, rem) \
    for (pos = head, rem = len; \
         nla_ok(pos, rem); \
         pos = nla_next(pos, &(rem)))

/**
 * @ingroup attr
 * Iterate over a stream of nested attributes
 * @arg pos loop counter, set to current attribute
 * @arg nla attribute containing the nested attributes
 * @arg rem initialized to len, holds bytes currently remaining in stream
 */
#define nla_for_each_nested(pos, nla, rem) \
    for (pos = nla_data(nla), rem = nla_len(nla); \
         nla_ok(pos, rem); \
         pos = nla_next(pos, &(rem)))


/* Variables used for netlink */
int nl_fd;  /* netlink socket's file descriptor */
struct sockaddr_nl nl_address; /* netlink socket address */
int nl_family_id; /* The family ID resolved by the netlink controller for this userspace program */
int nl_rxtx_length; /* Number of bytes sent or received via send() or recv() */
struct nlattr *nl_na; /* pointer to netlink attributes structure within the payload */
struct { /* memory for netlink request and response messages - headers are included */
    struct nlmsghdr n;
    struct genlmsghdr g;
    char buf[256];
} nl_request_msg, nl_response_msg;

/* Base on libnl-3 attr.c */

/**
 * Return type of the attribute.
 * @arg nla     Attribute.
 *
 * @return Type of attribute.
 */
int nla_type(const struct nlattr *nla)
{
    return nla->nla_type & NLA_TYPE_MASK;
}

/**
 * Return pointer to the payload section.
 * @arg nla     Attribute.
 *
 * @return Pointer to start of payload section.
 */
void *nla_data(const struct nlattr *nla)
{
    return (char *) nla + NLA_HDRLEN;
}

/**
 * Return length of the payload .
 * @arg nla     Attribute
 *
 * @return Length of payload in bytes.
 */
int nla_len(const struct nlattr *nla)
{
    return nla->nla_len - NLA_HDRLEN;
}

/**
 * Check if the attribute header and payload can be accessed safely.
 * @arg nla     Attribute of any kind.
 * @arg remaining   Number of bytes remaining in attribute stream.
 *
 * Verifies that the header and payload do not exceed the number of
 * bytes left in the attribute stream. This function must be called
 * before access the attribute header or payload when iterating over
 * the attribute stream using nla_next().
 *
 * @return True if the attribute can be accessed safely, false otherwise.
 */
int nla_ok(const struct nlattr *nla, int remaining)
{
    return remaining >= sizeof(*nla) &&
           nla->nla_len >= sizeof(*nla) &&
           nla->nla_len <= remaining;
}

/**
 * Return next attribute in a stream of attributes.
 * @arg nla     Attribute of any kind.
 * @arg remaining   Variable to count remaining bytes in stream.
 *
 * Calculates the offset to the next attribute based on the attribute
 * given. The attribute provided is assumed to be accessible, the
 * caller is responsible to use nla_ok() beforehand. The offset (length
 * of specified attribute including padding) is then subtracted from
 * the remaining bytes variable and a pointer to the next attribute is
 * returned.
 *
 * nla_next() can be called as long as remainig is >0.
 *
 * @return Pointer to next attribute.
 */
struct nlattr *nla_next(const struct nlattr *nla, int *remaining)
{
    int totlen = NLA_ALIGN(nla->nla_len);

    *remaining -= totlen;
    return (struct nlattr *) ((char *) nla + totlen);
}

static uint16_t nla_attr_minlen[NLA_TYPE_MAX+1] = {
    [NLA_U8]    = sizeof(uint8_t),
    [NLA_U16]   = sizeof(uint16_t),
    [NLA_U32]   = sizeof(uint32_t),
    [NLA_U64]   = sizeof(uint64_t),
    [NLA_STRING]    = 1,
    [NLA_FLAG]  = 0,
};

static int validate_nla(const struct nlattr *nla, int maxtype,
            const struct nla_policy *policy)
{
    const struct nla_policy *pt;
    unsigned int minlen = 0;
    int type = nla_type(nla);

    if (type < 0 || type > maxtype)
        return 0;

    pt = &policy[type];

    if (pt->type > NLA_TYPE_MAX)
        return -1;

    if (pt->minlen)
        minlen = pt->minlen;
    else if (pt->type != NLA_UNSPEC)
        minlen = nla_attr_minlen[pt->type];

    if (nla_len(nla) < minlen)
        return -2;

    if (pt->maxlen && nla_len(nla) > pt->maxlen)
        return -3;

    if (pt->type == NLA_STRING) {
        const char *data = nla_data(nla);
        if (data[nla_len(nla) - 1] != '\0')
            return -4;
    }

    return 0;
}

/**
 * Create attribute index based on a stream of attributes.
 * @arg tb      Index array to be filled (maxtype+1 elements).
 * @arg maxtype     Maximum attribute type expected and accepted.
 * @arg head        Head of attribute stream.
 * @arg len     Length of attribute stream.
 * @arg policy      Attribute validation policy.
 *
 * Iterates over the stream of attributes and stores a pointer to each
 * attribute in the index array using the attribute type as index to
 * the array. Attribute with a type greater than the maximum type
 * specified will be silently ignored in order to maintain backwards
 * compatibility. If \a policy is not NULL, the attribute will be
 * validated using the specified policy.
 *
 * @see nla_validate
 * @return 0 on success or a negative error code.
 */
int nla_parse(struct nlattr *tb[], int maxtype, struct nlattr *head, int len,
          struct nla_policy *policy)
{
    struct nlattr *nla;
    int rem, err;

    memset(tb, 0, sizeof(struct nlattr *) * (maxtype + 1));

    nla_for_each_attr(nla, head, len, rem) {
        int type = nla_type(nla);

        if (type > maxtype)
            continue;

        if (policy) {
            err = validate_nla(nla, maxtype, policy);
            if (err < 0)
                goto errout;
        }

        if (tb[type])
            fprintf(stderr, "Attribute of type %#x found multiple times in message, "
                  "previous attribute is being ignored.\n", type);

        tb[type] = nla;
    }

    if (rem > 0)
        fprintf(stderr, "netlink: %d bytes leftover after parsing "
               "attributes.\n", rem);

    err = 0;
errout:
    return err;
}

/**
 * Create attribute index based on nested attribute
 * @arg tb      Index array to be filled (maxtype+1 elements).
 * @arg maxtype     Maximum attribute type expected and accepted.
 * @arg nla     Nested Attribute.
 * @arg policy      Attribute validation policy.
 *
 * Feeds the stream of attributes nested into the specified attribute
 * to nla_parse().
 *
 * @see nla_parse
 * @return 0 on success or a negative error code.
 */
int nla_parse_nested(struct nlattr *tb[], int maxtype, struct nlattr *nla,
             struct nla_policy *policy)
{
    return nla_parse(tb, maxtype, nla_data(nla), nla_len(nla), policy);
}

static struct nla_policy ctrl_policy[CTRL_ATTR_MAX+1] = {
    [CTRL_ATTR_FAMILY_ID]   = { .type = NLA_U16 },
    [CTRL_ATTR_FAMILY_NAME] = { .type = NLA_STRING,
                    .maxlen = GENL_NAMSIZ },
    [CTRL_ATTR_VERSION] = { .type = NLA_U32 },
    [CTRL_ATTR_HDRSIZE] = { .type = NLA_U32 },
    [CTRL_ATTR_MAXATTR] = { .type = NLA_U32 },
    [CTRL_ATTR_OPS]     = { .type = NLA_NESTED },
    [CTRL_ATTR_MCAST_GROUPS] = { .type = NLA_NESTED },
};

static struct nla_policy family_grp_policy[CTRL_ATTR_MCAST_GRP_MAX+1] = {
    [CTRL_ATTR_MCAST_GRP_NAME] = { .type = NLA_STRING },
    [CTRL_ATTR_MCAST_GRP_ID]   = { .type = NLA_U32 },
};

int genlctrl_msg_parse(struct nlmsghdr *nlh, int *family_id, char **family_name, 
        int *mcast_id, char **mcast_name)
{
    struct nlattr *tb[CTRL_ATTR_MAX+1];
    struct nlattr *nla_hdr;
    int nla_length;
    int ret = 0;

    nla_hdr = (struct nlattr *)((unsigned char *) nlh + NLMSG_HDRLEN + GENL_HDRLEN);
    nla_length = nlh->nlmsg_len - GENL_HDRLEN - NLMSG_HDRLEN;

    if(ret = nla_parse(tb, CTRL_ATTR_MAX, nla_hdr, nla_length, ctrl_policy)) {
        fprintf(stderr, "nla_parse error! ret = %d\n", ret);
        return -1;
    }

    if (tb[CTRL_ATTR_FAMILY_ID])
        *family_id = *(const uint16_t *) nla_data(tb[CTRL_ATTR_FAMILY_ID]);

    if (tb[CTRL_ATTR_FAMILY_NAME])
        *family_name = (char *) nla_data(tb[CTRL_ATTR_FAMILY_NAME]);

    if (tb[CTRL_ATTR_MCAST_GROUPS]) {
        struct nlattr *nla, *grp_attr;
        int remaining, err;

        grp_attr = tb[CTRL_ATTR_MCAST_GROUPS];
        nla_for_each_nested(nla, grp_attr, remaining) {
            struct nlattr *tb[CTRL_ATTR_MCAST_GRP_MAX+1];
            int id = 0;
            char *name = NULL;

            err = nla_parse_nested(tb, CTRL_ATTR_MCAST_GRP_MAX, nla,
                       family_grp_policy);
            if (err < 0) {
                fprintf(stderr, "nla_parse_nested error! err = %d\n", err);
                return -1;
            }

            if (tb[CTRL_ATTR_MCAST_GRP_ID])
                id = *(const uint32_t *) nla_data(tb[CTRL_ATTR_MCAST_GRP_ID]);

            if (tb[CTRL_ATTR_MCAST_GRP_NAME])
                name = (char *) nla_data(tb[CTRL_ATTR_MCAST_GRP_NAME]);

            if (id || name) {
                *mcast_id = id;
                *mcast_name = name;
            }
        }
    }

    return 0;
}

void genlmsg_recv(void) {
    struct nlmsghdr *nlh;
    struct nlattr *tb[__ATTR_MAX];
    struct nlattr *nla_hdr;
    int nla_length;
    int ret = 0;

    while(1)
    {
    memset(&nl_response_msg, 0, sizeof(nl_response_msg));
    nl_rxtx_length = recv(nl_fd, &nl_response_msg, sizeof(nl_response_msg), 0);
    if (nl_rxtx_length < 0) {
        perror("recv()");
        goto out;
    }

    nlh = &nl_response_msg.n;
    nla_hdr = (struct nlattr *)((unsigned char *) nlh + NLMSG_HDRLEN + GENL_HDRLEN);
    nla_length = nlh->nlmsg_len - GENL_HDRLEN - NLMSG_HDRLEN;

    if(ret = nla_parse(tb, __ATTR_MAX-1, nla_hdr, nla_length, NULL)) {
        fprintf(stderr, "nla_parse error! ret = %d\n", ret);
        goto out;
    }

    if (tb[1])
        printf("ATTR_HELLO: len:%u type:%u data:%s\n", tb[1]->nla_len,
                tb[1]->nla_type, (char *)nla_data(tb[1]));
    else
        printf("ATTR_HELLO: null\n");

    if (tb[2])
        printf("ATTR_FOO: len:%u type:%u data:%u\n", tb[2]->nla_len,
                tb[2]->nla_type, *((__u32 *)nla_data(tb[2])));
    else
        printf("ATTR_FOO: null\n");
    }
out:
    return;
}

int main(void) {
    struct nlattr *nla1, *nla2;
    int len, rem, remaining;
    struct nlmsghdr *nlh;
    int family_id;
    char *family_name;
    int mcast_id;
    char *mcast_name;
    int err;

    /* Step 1: Open the socket. Note that protocol = NETLINK_GENERIC */
    nl_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_GENERIC);
    if (nl_fd < 0) {
        perror("socket()");
        return -1;
    }

    /* Step 2: Bind the socket. */
    memset(&nl_address, 0, sizeof(nl_address));
    nl_address.nl_family = AF_NETLINK;
    nl_address.nl_groups = 0;

    if (bind(nl_fd, (struct sockaddr *) &nl_address, sizeof(nl_address)) < 0) {
        perror("bind()");
        goto out;
    }

    /* Step 3: Resolve the family ID corresponding to the string GEN_FAMILY_STR  */
    /* Populate the netlink header */
    nl_request_msg.n.nlmsg_type = GENL_ID_CTRL;
    nl_request_msg.n.nlmsg_flags = NLM_F_REQUEST;
    nl_request_msg.n.nlmsg_seq = 0;
    nl_request_msg.n.nlmsg_pid = getpid();
    nl_request_msg.n.nlmsg_len = NLMSG_LENGTH(GENL_HDRLEN);
    /* Populate the payload's "family header" : which in our case is genlmsghdr */
    nl_request_msg.g.cmd = CTRL_CMD_GETFAMILY;
    nl_request_msg.g.version = 0x1;
    /* Populate the payload's "netlink attributes" */
    nl_na = (struct nlattr *) GENLMSG_DATA(&nl_request_msg); /* get location of genl data where to put */
    nl_na->nla_type = CTRL_ATTR_FAMILY_NAME;
    nl_na->nla_len = strlen(GEN_FAMILY_STR) + 1 + NLA_HDRLEN;
    strcpy(NLA_DATA(nl_na), GEN_FAMILY_STR); /* Family name length can be upto 16 chars including \0 */

    nl_request_msg.n.nlmsg_len += NLMSG_ALIGN(nl_na->nla_len);

    memset(&nl_address, 0, sizeof(nl_address));
    nl_address.nl_family = AF_NETLINK;

    /* Send the family ID request message to the netlink controller */
    nl_rxtx_length = sendto(nl_fd, (char *) &nl_request_msg, nl_request_msg.n.nlmsg_len, 
        0, (struct sockaddr *) &nl_address, sizeof(nl_address));
    if (nl_rxtx_length != nl_request_msg.n.nlmsg_len) {
        perror("sendto()");
        goto out;
    }

    /* Wait for the response message */
    nl_rxtx_length = recv(nl_fd, &nl_response_msg, sizeof(nl_response_msg), 0);
    if (nl_rxtx_length < 0) {
        perror("recv()");
        goto out;
    }

    /* Validate response message */
    if (!NLMSG_OK((&nl_response_msg.n), nl_rxtx_length)) {
        fprintf(stderr, "family ID request : invalid message\n");
        goto out;
    }
    if (nl_response_msg.n.nlmsg_type == NLMSG_ERROR) { /* error */
        fprintf(stderr, "family ID request : receive error\n");
        goto out;
    }

    /* Step 4: Extract family ID and mcast group ID*/
    nlh = &nl_response_msg.n;
    genlctrl_msg_parse(nlh, &family_id, &family_name, &mcast_id, &mcast_name);
    printf("[INFO] family_id = %d, family_name = %s\n", family_id, family_name);
    printf("[INFO] mcast_id = %d, mcast_name = %s\n", mcast_id, mcast_name);

    /* Step 5: Add to mulitcast group */
    err = setsockopt(nl_fd, SOL_NETLINK, NETLINK_ADD_MEMBERSHIP, &mcast_id, sizeof(mcast_id));
    if (err < 0) {
        perror ("setsockopt()");
        goto out;
    }

    /* Step 6: Receive multicast data */
    genlmsg_recv();

    /* Step 7: Close the socket and quit */
    close(nl_fd);
    return 0;

out:
    close(nl_fd);
    return -1;
}