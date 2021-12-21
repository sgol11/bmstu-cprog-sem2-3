#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "main.h"

node_t *create_node(int data);
void free_list(node_t **head);
void push(node_t *element, node_t **head);

#endif