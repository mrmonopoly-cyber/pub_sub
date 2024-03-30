#pragma once

#include "connections.h"
typedef struct channel channel;

int sub_to_channel(channel* ch, address* addr);
void channel_free(channel* ch);
int channel_cmp(const channel* ch1, const channel* ch2);
void channel_print(const channel* ch);

unsigned int channel_sizeof();

