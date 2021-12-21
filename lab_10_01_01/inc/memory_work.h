#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "main.h"
#include "structs.h"

void free_movie_list(node_t **head);
void free_movie_node(node_t **node);
void free_int_list(node_t **head);
void free_int_node(node_t **node);

#endif