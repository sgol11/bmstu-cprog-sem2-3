#include "read_from_file.h"

int read_file(char *file_name, int *n, product_t **products_arr)
{
    int rc = OK;

    FILE *file = fopen(file_name, "r");

    if (!file)
        rc = ERR_NO_FILE;

    if (rc == OK)
    {
        rc = read_products_num(file, n);

        if (rc == OK)
        {
            *products_arr = malloc((*n) * sizeof(product_t));

            if (!(*products_arr))
            {
                *n = 0;
                rc = ERR_MEMORY;
            }
            else
                init_structs_arr(*products_arr, *n);
        }

        if (rc == OK)
            rc = read_structs(file, *products_arr, *n);

        fclose(file);
    }

    return rc;
}

int read_products_num(FILE *f, int *n)
{
    int rc = OK;

    if (!f)
        rc = ERR_NO_FILE;
    else
    {
        *n = my_getnum(f, &rc);
        
        if (*n <= 0)
            rc = ERR_PROD_NUM;
    }
    
    return rc;
}

int read_structs(FILE *f, product_t *products_arr, int products_num)
{
    int rc = OK;
    int i = 0;

    while (rc == OK && !feof(f) && !ferror(f) && i < products_num)
    {
        char *tmp_name = NULL;
        int tmp_price = 0;

        rc = read_product_info(f, &tmp_name, &tmp_price);

        if (rc == OK)
        {
            product_create(tmp_name, tmp_price, products_arr);
            if (!products_arr->name)
                rc = ERR_MEMORY;
        }
        
        free(tmp_name);
        tmp_name = NULL;

        products_arr++;
        i++;
    }

    if (rc == OK && products_num > i)
        rc = ERR_PROD_NUM;

    return rc;
}

int read_product_info(FILE *f, char **tmp_name, int *tmp_price)
{
    int rc = OK; 
    *tmp_name = NULL;

    if (!f)
        rc = ERR_NO_FILE;
    else
    {
        char *line = NULL;
        int len = 0;

        int tmp = my_getline(&line, &len, f);

        if (tmp != -1 && tmp != 0)
        {
            *tmp_name = malloc((len + 1) * sizeof(char));

            if (!(*tmp_name))
                rc = ERR_MEMORY;
            else
                strcpy(*tmp_name, line);

            free(line);
            line = NULL;
        }
        else
            rc = ERR_MEMORY;
        
        if (len == 1)
            rc = ERR_EMPTY_STR;
        
        *tmp_price = my_getnum(f, &rc);
        
        if (*tmp_price <= 0)
            rc = ERR_PRICE;
    }

    return rc;
}

void product_create(char *name, int price, product_t *pr)
{
    pr->name = strdup(name);
    
    if (pr->name)
        pr->price = price;
}
