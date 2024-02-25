#pragma once

#include "connections.h"


typedef struct broker broker;

//server
broker* init_broker(const address* addr, const unsigned int port);
void start_listening(broker* br);
void close_listening(broker* br);
void free_broker(broker* br);
//client
void subscribe_to_channel_broker(const address* br_addr, const char** chann_subs, 
        const unsigned int ch_num);
void publish_broker(const address* br_addr, const char** chann_subs, const unsigned int ch_num, 
        const void* data,const unsigned int data_size);

