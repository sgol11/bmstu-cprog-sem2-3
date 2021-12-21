#ifndef __IO_H__
#define __IO_H__

#include "main.h"
#include "constants.h"
#include "memory_work.h"
#include "factoring_operations.h"

int input_command(void);
int input_numbers(int command, int *num_1, int *num_2);
void print_polynomial_factoring(node_t *head);

#endif