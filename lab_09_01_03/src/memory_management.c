#include "memory_management.h"

void init_structs_arr(product_t *products_arr, int n)
{
    for (int i = 0; i < n; i++)
        init_struct(products_arr + i);
}

void init_struct(product_t *product)
{
    product->name = NULL;
    product->price = 0;
}

void free_structs_arr(product_t **products_arr, int n)
{
    for (int i = 0; i < n; i++)
        free_struct((*products_arr) + i);
        
    free(*products_arr);
    *products_arr = NULL;
}

void free_struct(product_t *product)
{
    free(product->name);
    product->name = NULL;
    product->price = 0;
}