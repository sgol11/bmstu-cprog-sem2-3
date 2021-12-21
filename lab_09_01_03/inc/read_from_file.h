#ifndef READ_FROM_FILE_H
#define READ_FROM_FILE_H

#include "main.h"
#include "errors.h"
#include "my_functions.h"
#include "memory_management.h"

int read_file(char *file_name, int *n, product_t **products_arr);
int read_products_num(FILE *f, int *n);
int read_structs(FILE *f, product_t *products_arr, int products_num);
int read_product_info(FILE *f, char **tmp_name, int *tmp_price);
void product_create(char *name, int price, product_t *pr);

#endif