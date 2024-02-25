#pragma once

#include "channel.h"

#define IP_ADDR_SECTORS 4

typedef struct broker broker;

typedef struct address{//0.0.0.0 - 255.255.255.255
    unsigned int addr_sectors[IP_ADDR_SECTORS];
    unsigned int port;
}address;

broker* init_broker(const address *addr, const unsigned int port);
void publish_broker(broker* br, const char* chann_subs[], const void* data,const unsigned int data_size);
void subscribe_to_channel_broker(broker* br, const char* chann_subs[]);

void free_broker(broker* br);
