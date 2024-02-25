#include "channel.h"

typedef struct sub_ch{
    const char* addr;
    const unsigned int port;
}sub_ch;

struct channel{
    const unsigned int _ch_id;
    char* ch_name;
    sub_ch* subs_list;
};
