#include "choose_products.h"

int choose_products(product_t *init, product_t **res, int n, double p)
{
    int new_n = count_new_n(init, n, p);

    *res = malloc(new_n * sizeof(product_t));

    if (!(*res))
        new_n = ERR_MEMORY;
    else
    {
        init_structs_arr(*res, new_n);
        
        int j = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (j < new_n && init[i].price < p)
            {
                product_create(init[i].name, init[i].price, (*res) + j);
                j++;
            }
        }
    }

    return new_n;
}

int count_new_n(product_t *init, int n, double p)
{
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (init[i].price < p)
            cnt++;
    }
	
    return cnt;
}
