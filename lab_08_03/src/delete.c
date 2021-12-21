#include "delete.h"

int square_matrix_by_removing(matrix_t *matr)
{
    int rc = OK;
    int removed_axis = matr->rows > matr->columns ? 1 : 2;
    int idx = 0;
    int init_rows = matr->rows;

    while (matr->rows != matr->columns)
    {
        idx = first_max_by_columns_idx(matr, removed_axis);

        if (removed_axis == 1)
            matr->rows = shift_rows(matr, idx);
        else
            matr->columns = shift_columns(matr, idx);
    }
    
    if (removed_axis == 1)
        rc = delete_rows_memory(matr, init_rows);
    else
        rc = delete_columns_memory(matr);

    return rc;
}

int first_max_by_columns_idx(matrix_t *matr, int axis)
{
    int max = matr->data[0][0] - 1;
    int i_max = 0, j_max = 0;

    for (int j = 0; j < matr->columns; j++)
    {
        for (int i = 0; i < matr->rows; i++)
        {
            if (matr->data[i][j] > max)
            {
                max = matr->data[i][j];
                i_max = i;
                j_max = j;
            }
        }
    }

    return axis == 1 ? i_max : j_max;
}

int shift_rows(matrix_t *matr, int row_idx)
{
    for (int i = row_idx; i < matr->rows - 1; i++)
        for (int j = 0; j < matr->columns; j++)
            matr->data[i][j] = matr->data[i + 1][j];

    return matr->rows - 1;
}

int shift_columns(matrix_t *matr, int col_idx)
{
    for (int i = 0; i < matr->rows; i++)
        for (int j = col_idx; j < matr->columns - 1; j++)
            matr->data[i][j] = matr->data[i][j + 1];

    return matr->columns - 1;
}