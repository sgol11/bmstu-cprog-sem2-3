#include "memory_work.h"

int **allocate_matrix(int n, int m)
{
    int rc = OK;
    int **data = NULL;
    
    data = malloc(n * sizeof(int*));

    if (!data)
        rc = ERR_MEMORY;
    else
    {
        for (int i = 0; i < n && rc == OK; i++)
        {
            data[i] = malloc(m * sizeof(int));
            if (!data[i])
            {
                free_matrix(data, i);
                rc = ERR_MEMORY;
            }
        }
    }
    
    return data;
}

void free_matrix(int **data, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(data[i]);
        data[i] = NULL;
    } 

    free(data);
    data = NULL;
}

int delete_rows_memory(matrix_t *matr, int init_rows)
{
    int rc = OK;
    int **tmp_data = NULL;
    int new_rows = matr->rows;

    for (int i = new_rows; i < init_rows; i++)
    {
        free(matr->data[i]);
        matr->data[i] = NULL;
    }

    tmp_data = realloc(matr->data, new_rows * sizeof(int*));

    if (!tmp_data)
        rc = ERR_MEMORY;
    else
        matr->data = tmp_data;

    return rc;
}

int delete_columns_memory(matrix_t *matr)
{
    int rc = OK;

    for (int i = 0; i < matr->rows && rc == OK; i++)
    {
        int *tmp_row = NULL;

        tmp_row = realloc(matr->data[i], matr->columns * sizeof(int));

        if (!tmp_row)
            rc = ERR_MEMORY;
        else
            matr->data[i] = tmp_row;
    }

    return rc;
}

int add_rows_memory(matrix_t *matr, int final_rows)
{
    int rc = OK;
    int **tmp_data = NULL;

    tmp_data = realloc(matr->data, final_rows * sizeof(int*));

    if (!tmp_data)
        rc = ERR_MEMORY;
    else
    {
        for (int i = matr->rows; i < final_rows && rc == OK; i++)
        {
            tmp_data[i] = malloc(matr->columns * sizeof(int));
            if (!tmp_data[i])
            {
                free_matrix(tmp_data, i);
                rc = ERR_MEMORY;
            }
        }
        if (rc == OK)
            matr->data = tmp_data;
    }

    return rc;
}

int add_columns_memory(matrix_t *matr, int final_columns)
{
    int rc = OK;

    for (int i = 0; i < matr->rows && rc == OK; i++)
    {
        int *tmp_row = NULL;

        tmp_row = realloc(matr->data[i], final_columns * sizeof(int));

        if (!tmp_row)
            rc = ERR_MEMORY;
        else
            matr->data[i] = tmp_row;
    }

    return rc;
}