#pragma once

typedef char channel[];

typedef struct broker broker;
typedef struct subscriber 
{
    unsigned long port;
    char ip_addr[];
}subscriber;

broker* init_broker();

void publish(broker* br, const channel ch, const void* data,const unsigned int data_size );
channel* channel_list(const broker* br); 
void subscribe_to_channel(broker* br, const channel ch,const subscriber *sub);
