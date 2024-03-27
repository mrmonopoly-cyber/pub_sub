#pragma once

#include "connections.h"


typedef struct broker broker;

//server
broker* broker_init(const address* addr, const unsigned int port);
void broker_start_listening(broker* br);
void broker_close_listening(broker* br);
address* broker_get_addr(const broker *br);
void broker_free(broker* br);
//client
void broker_subscribe_to_channel_broker(const address* br_addr, const char** chann_subs, 
        const unsigned int ch_num);
void broker_publish_broker(const address* br_addr, const char** chann_subs, const unsigned int ch_num, 
        const void* data,const unsigned int data_size);

