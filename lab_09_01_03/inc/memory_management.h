#ifndef MEMORY_H
#define MEMORY_H

#include "main.h"

void init_structs_arr(product_t *products_arr, int n);
void init_struct(product_t *product);

void free_structs_arr(product_t **products_arr, int n);
void free_struct(product_t *product);

#endif