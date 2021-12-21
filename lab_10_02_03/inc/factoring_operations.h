#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

#include "main.h"
#include "constants.h"
#include "memory_work.h"

int polynomial_factoring(int num, node_t **head);
int is_prime(int num);

int multiplication(node_t *head_1, node_t *head_2, node_t **res_head);

int squaring(node_t *head, node_t **res_head);

int division(node_t *head_1, node_t *head_2, node_t **res_head);
int number_from_factoring(node_t *head);

#endif