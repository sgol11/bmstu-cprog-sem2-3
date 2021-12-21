#ifndef __ONE_ELEMENT_H__
#define __ONE_ELEMENT_H__

#include "main.h"
#include "structs.h"
#include "memory_work.h"

node_t *create_int_node(int num);
node_t *create_int_list(int num);

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));
void *pop_front(node_t **head);
void *pop_back(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);

int comparator_int(const void *first_element, const void *second_element);
int comparator_movie(const void *first_element, const void *second_element);

#endif
