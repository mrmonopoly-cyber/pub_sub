#include "channel.h"
#include "connections.h"

struct channel{
    const unsigned int _ch_id;
    char* ch_name;
    address* subs_list;
};
