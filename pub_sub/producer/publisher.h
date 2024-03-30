#pragma once

#include "../utility/connections.h"

typedef struct publisher publisher;

publisher* init_publisher(const address* broker_addr);
int publisher_publish(const publisher* pub, const char** channels, 
        const void* data, const unsigned int data_size);

