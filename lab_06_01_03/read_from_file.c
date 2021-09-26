#include "read_from_file.h"

int read_file(char *file_name, product *products_arr, int *n)
{
    int code = OK;

    FILE *file = fopen(file_name, "r");

    if (!file)
        code = ERR_NO_FILE;

    if (code == OK)
    {
        code = read_products_num(file, n);

        if (code == OK)
            code = read_structs(file, products_arr, *n, code);

        fclose(file);
    }

    return code;
}

int read_products_num(FILE *f, int *n)
{
    int code = OK;

    if (!f)
        code = ERR_NO_FILE;
    else
    {
        if (fscanf(f, "%d", n) == 0)
            code = ERR_PROD_NUM;
        else if (*n <= 0 || *n > MAX_ARR_SIZE)
            code = ERR_PROD_NUM;
    }
    
    return code;
}

int read_structs(FILE *f, product *products_arr, int products_num, int code)
{
    int i = 0;

    while (code == OK && !feof(f) && !ferror(f) && i < products_num)
    {
        code = read_product_info(f, products_arr + i);
        i++;
    }

    return code;
}

int read_product_info(FILE *f, product *pr)
{
    int code = OK; 

    if (!f)
        code = ERR_NO_FILE;
    else
    {
        fscanf(f, "%s", pr->name);
        if (strlen(pr->name) > MAX_NAME_SIZE)
            code = ERR_NAME;

        if (fscanf(f, "%d", &(pr->price)) == 0)
            code = ERR_PRICE;
        else if (pr->price <= 0)
            code = ERR_PRICE;
    }

    return code;
}