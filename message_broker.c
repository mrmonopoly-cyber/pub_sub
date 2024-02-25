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
};

struct sub_pack
{
    const enum pack_type _pkg_type;
    const char* _list_ch;
};


static void 
print_address(const address* addr)
{
    int i=0;
    for (i =0; i<IP_ADDR_SECTORS-1; i++) {
        fprintf(stderr,"%d.", addr->addr_sectors[i]);
    }
    fprintf(stderr,"%d", addr->addr_sectors[i]);
}

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
publish_broker(const address* br_addr, const char* chann_subs[], 
        const void* data,const unsigned int data_size)
{
    
}

void 
subscribe_to_channel_broker(const address* br_addr, const char* chann_subs[], const unsigned int ch_num)
{
    int i =0;
    struct sub_pack sub_req =
    {
        ._pkg_type = SUBSCRIBTION,
        ._list_ch = NULL,
    };

    for(i=0;i<ch_num;i++)
    {
        sub_req._list_ch = chann_subs[i];
        send_connections(br_addr, &sub_req, sizeof(sub_req) + strlen(chann_subs[i]));
    }
}

void 
free_broker(broker* br);
