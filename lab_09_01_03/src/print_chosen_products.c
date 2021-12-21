#include "print_chosen_products.h"

void print_products(product_t *res_arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        product_t *pr = res_arr + i;
        print_product(pr);
    }
}

void print_product(product_t *pr)
{
    printf("%s%u\n", pr->name, pr->price);
}