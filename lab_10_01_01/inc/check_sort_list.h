#ifndef __C_SORT_LIST__H__
#define __C_SORT_LIST__H__

#include "check_main.h"
#include "main.h"
#include "structs.h"
#include "memory_work.h"
#include "one_element.h"
#include "sort_list.h"

node_t *create_not_sorted_list(int n);
Suite* check_sort_list(void);

#endif