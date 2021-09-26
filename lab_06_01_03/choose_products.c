#include "choose_products.h"

int choose_products(product *init, product *res, int n, double p)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        product *pr = init + i;

        if (pr->price < p)
        {
            res[j] = init[i];
            j++;
        }
    }
	
    return j;
}