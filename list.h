#pragma once

typedef struct list list;

typedef void* (*fun_op) (void *args);


void foreach_list(list* l, fun_op fun);
