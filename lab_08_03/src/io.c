#include "io.h"

int input_matrix(matrix_t *matr)
{
    int rc = OK;
    int check = 0;
    
    check = scanf("%d", &matr->rows);
    if (check != 1 || matr->rows <= 0)
        rc = ERR_SIZE;
    
    check = scanf("%d", &matr->columns);
    if (rc == OK && (check != 1 || matr->columns <= 0))
        rc = ERR_SIZE;
    
    if (rc == OK)
    {
        matr->data = allocate_matrix(matr->rows, matr->columns);
        if (matr->data == NULL)
            rc = ERR_MEMORY;
    }

    if (rc == OK)
    {
        for (int i = 0; i < matr->rows && rc == OK; i++)
            for (int j = 0; j < matr->columns && rc == OK; j++)
            {
                int cur_elem = 0;
                check = scanf("%d", &cur_elem);

                if (check != 1)
                    rc = ERR_ELEMENT;
                else
                    matr->data[i][j] = cur_elem;
            }
    }

    return rc;
}

void print_matrix(matrix_t *matr)
{
    for (int i = 0; i < matr->rows; i++)
    {
        for (int j = 0; j < matr->columns; j++)
            printf("%d ", matr->data[i][j]);
        printf("\n");
    }
}

int input_powers(int *p, int *q)
{
    int rc = OK;
    int check = 0;

    check = scanf("%d", p);
    if (check != 1 || *p < 0)
        rc = ERR_POW;
    
    check = scanf("%d", q);
    if (rc == OK && (check != 1 || *q < 0))
        rc = ERR_POW;

    return rc;
}