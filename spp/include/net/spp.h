/*
 * Declarations of SPP type objects.
 *
 * Jacob Holtom
 */

#include <linux/spp.h>
#include <linux/spinlock.h>
#include <linux/timer.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <net/neighbour.h>
#include <net/sock.h>

#define SPP_HEADER_LEN 32 /* 32 bit header length */
#define SPP_APID_LEN 11 /* 11 bit APID length */

#define SPP_OUT_OF_ORDER 0

struct spp_entity {
/* An end of the connection - May not need because we have no true 'routing' support */
};

struct spp_sock {
    struct sock sock;
    spp_address s_addr, d_addr;
    struct net_device *device;
    unsigned int lci, rand;
    unsigned char state, condition, qbitincl, defer;
    unsigned char cause, diagnostic;
    struct sk_buff_head ack_queue;
    struct sk_buff_head fragment_queue;
    struct sk_buff_head interrupt_in_queue;
    struct sk_buff_head interrupt_out_queue;
    struct spp_facilities_struct facilities;
};

#define spp_sk(sk) ((struct spp_sock *)(sk))

struct spp_dev {
    struct spp_dev *next;
    struct net_device *dev;
};

/* af_spp.c */

/* spp_addr.c */
extern char *spp2ascii(char *buf, const spp_address *addr);
extern void asii2spp(spp_address *addr, const char *buf);
extern int sppcmp(spp_address *addr1, spp_address *addr2);
extern int sppval(struct spp_address *addr);
/* spp_loopback.c */

/* spp_methods.c */
extern void spp_disconnect(struct sock *sk, int reason, unsigned char cause, unsigned char diagnostic);
/* spp_out.c */

/* sysctl_net_spp.c */
