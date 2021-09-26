#ifndef READ_FROM_FILE_H
#define READ_FROM_FILE_H

#include "main.h"

#define ERR_NO_FILE 2
#define ERR_NAME 3
#define ERR_PRICE 4
#define ERR_PROD_NUM 5

#define MAX_LINE_SIZE 40

int read_file(char *file_name, product *products_arr, int *n);
int read_products_num(FILE *f, int *n);
int read_structs(FILE *f, product *products_arr, int products_num, int code);
int read_product_info(FILE *f, product *pr);

#endif