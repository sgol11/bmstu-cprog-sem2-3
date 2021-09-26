#include "print_chosen_products.h"

void print_products(product *res_arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        product *pr = res_arr + i;
        print_product(pr);
    }
}

void print_product(product *pr)
{
    printf("%s\n%u\n", pr->name, pr->price);
}