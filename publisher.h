#pragma once

#include "message_borker.h"

typedef void * (*production_function)(void *) ;

typedef struct publisher publisher;

publisher* init_publisher(const production_function fun);
void publisher_produce_and_publish(void * args);

