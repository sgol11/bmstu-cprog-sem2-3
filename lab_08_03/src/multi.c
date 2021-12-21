#include "multi.h"

int calculate(matrix_t *first_matr, int first_pow, matrix_t *second_matr, 
int second_pow, matrix_t *res_matr)
{
    int rc = OK;

    if (first_pow == 0)
        make_identity_matrix(first_matr);
    if (second_pow == 0)
    {
        make_identity_matrix(second_matr);
        second_pow = 1;
    }

    res_matr->data = allocate_matrix(first_matr->rows, first_matr->columns);

    if (res_matr->data == NULL)
        rc = ERR_MEMORY;

    if (rc == OK)
    {
        copy_matrix(first_matr, res_matr);
        
        for (int i = 1; i < first_pow && rc == OK; i++)
            rc = assign_multi_res(res_matr, first_matr);

        for (int i = 0; i < second_pow && rc == OK; i++)
            rc = assign_multi_res(res_matr, second_matr);
    }

    return rc;
}

int assign_multi_res(matrix_t *res, matrix_t *multiplier)
{
    int rc = OK;
    matrix_t tmp;

    rc = multiply(res, multiplier, &tmp);

    if (rc == OK)
    {
        copy_matrix(&tmp, res);
        free_matrix(tmp.data, tmp.rows);
    }

    return rc;
}

void copy_matrix(matrix_t *src, matrix_t *dst)
{
    for (int i = 0; i < src->rows; i++)
        for (int j = 0; j < src->columns; j++)
            dst->data[i][j] = src->data[i][j];

    dst->rows = src->rows;
    dst->columns = src->columns;
}

void make_identity_matrix(matrix_t *matr)
{
    for (int i = 0; i < matr->rows; i++)
        for (int j = 0; j < matr->columns; j++)
        {
            if (i == j)
                matr->data[i][j] = 1;
            else
                matr->data[i][j] = 0;
        }
}

int multiply(matrix_t *m1, matrix_t *m2, matrix_t *res)
{
    int rc = OK;

    res->data = allocate_matrix(m1->rows, m2->columns);

    if (res->data == NULL)
        rc = ERR_MEMORY;
    else
    {
        for (int i_a = 0; i_a < m1->rows; i_a++)
        {
            for (int j_b = 0; j_b < m2->columns; j_b++)
            {
                res->data[i_a][j_b] = 0;
                for (int idx = 0; idx < m2->rows; idx++)
                    res->data[i_a][j_b] += m1->data[i_a][idx] * m2->data[idx][j_b];
            }
        }

        res->rows = m1->rows;
        res->columns = m2->columns;
    }

    return rc;
}