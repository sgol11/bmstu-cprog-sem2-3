#ifndef __C_ONE_ELEMENT__H__
#define __C_ONE_ELEMENT__H__

#include "check_main.h"
#include "main.h"
#include "structs.h"
#include "memory_work.h"
#include "one_element.h"

node_t *create_int_node(int num);
node_t *create_int_list(int n);
Suite* check_one_element(void);

#endif