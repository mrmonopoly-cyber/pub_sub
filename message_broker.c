#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "channel.h"
#include "message_borker.h"
#include "connections.h"


struct broker 
{
    address _addr; 
    channel* _list_ch;
    char listening:1;
};

enum pack_type
{
    SUBSCRIBTION,
    PUBLISHING,
};

struct req_pack
{
    const enum pack_type _pkg_type;
    const char** _list_ch;
    const void* data;
    const unsigned int data_amount;
};

//private
static void 
print_address(const address* addr)
{
    int i=0;
    for (i =0; i<IP_ADDR_SECTORS-1; i++) {
        fprintf(stderr,"%d.", addr->addr_sectors[i]);
    }
    fprintf(stderr,"%d", addr->addr_sectors[i]);
}

static void
send_request(const address* br_addr, struct req_pack* pkg,const char **chann_subs, const int ch_num)
{
    int i=0;
    for(i=0;i<ch_num;i++)
    {
        send_connections(br_addr, pkg, sizeof(*pkg) + strlen(chann_subs[i]));
    }
}
//public
broker* 
init_broker(const address* addr, const unsigned int port)
{
    broker* br_init= calloc(1, sizeof(*br_init));
    const unsigned short* new_addr = addr->addr_sectors;

    for(int i=0;i<IP_ADDR_SECTORS;i++){
        if(new_addr[i] < 0 ||  new_addr[i] > 255){
            fprintf(stderr,"invalid ip address %d is not a valid value in ", new_addr[i]); 
            print_address(addr);
            fprintf(stderr, "\n");
            return NULL;
        }
        br_init->_addr.addr_sectors[i] = new_addr[i];
    }

    br_init->_addr.port = addr->port;
    br_init->_list_ch=0;

    return br_init;
}

void 
start_listening(broker* br)
{

}

void 
close_listening(broker* br)
{

}

void 
publish_broker(const address* br_addr, const char** chann_subs, const unsigned int ch_num, 
        const void* data,const unsigned int data_size)
{
    struct req_pack pub_req=
    {
        ._pkg_type = SUBSCRIBTION,
        ._list_ch = chann_subs,
        .data=data,
        .data_amount=data_size,
    };
    send_request(br_addr, &pub_req, chann_subs, ch_num);
}

void 
subscribe_to_channel_broker(const address* br_addr, const char** chann_subs, 
        const unsigned int ch_num)
{
    struct req_pack sub_req =
    {
        ._pkg_type = SUBSCRIBTION,
        ._list_ch = chann_subs,
        .data=NULL,
        .data_amount=0,
    };
    send_request(br_addr, &sub_req, chann_subs, ch_num);
}

void 
free_broker(broker* br)
{

}
