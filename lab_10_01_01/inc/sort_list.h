#ifndef __SORT_H__
#define __SORT_H__

#include "main.h"
#include "structs.h"

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void front_back_split(node_t *head, node_t **back);
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));
void create_res_list(node_t **res_list, node_t **res_head, node_t **src_list);
void move_elem_to_res_list(node_t **res_list, node_t **src_list);

#endif