#ifndef CHOOSE_PRODUCTS_H
#define CHOOSE_PRODUCTS_H

#include "main.h"
#include "errors.h"
#include "memory_management.h"
#include "read_from_file.h"

int choose_products(product_t *init, product_t **res, int n, double p);
int count_new_n(product_t *init, int n, double p);

#endif