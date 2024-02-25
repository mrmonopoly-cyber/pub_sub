#pragma once

#define IP_ADDR_SECTORS 4

typedef void* (* recv_fun) (void *);
typedef struct address{//0.0.0.0 - 255.255.255.255
    unsigned short addr_sectors[IP_ADDR_SECTORS];
    unsigned short port;
}address;

void send_connections(const address* addr, const void *data, const unsigned int data_amount);
void recv_connections(address* o_client_addr, recv_fun fun, void *args);
