#ifndef __WHOLE_LIST_H__
#define __WHOLE_LIST_H__

#include "main.h"
#include "structs.h"

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*));

#endif