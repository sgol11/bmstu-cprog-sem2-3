#include "add.h"

int one_size_by_adding(matrix_t *a, matrix_t *b)
{
    int rc = OK;

    int increased_matr = a->rows < b->rows ? 1 : 2;
    int final_size = a->rows > b->rows ? a->rows : b->rows;
    
    if (increased_matr == 1)
        rc = form_matrix_by_adding(a, final_size);
    else
        rc = form_matrix_by_adding(b, final_size);

    return rc;
}

int form_matrix_by_adding(matrix_t *matr, int final_size)
{
    int rc = OK;

    rc = add_rows_memory(matr, final_size);

    if (rc == OK)
    {
        for (int i = matr->rows; i < final_size; i++)
        {
            for (int j = 0; j < matr->columns; j++)
                matr->data[i][j] = column_avg(matr->data, i, j);
        }
        matr->rows = final_size;

        rc = add_columns_memory(matr, final_size);
    }

    if (rc == OK)
    {
        for (int j = matr->columns; j < final_size; j++)
        {
            for (int i = 0; i < matr->rows; i++)
                matr->data[i][j] = row_max(matr->data, j, i);
        }
        matr->columns = final_size;
    }

    return rc;
}

int column_avg(int **matr, int rows, int column_idx)
{
    int sum = 0, cnt = rows;

    for (int i = 0; i < rows; i++)
        sum += matr[i][column_idx];

    return sum > 0 || sum % cnt == 0 ? sum / cnt : sum / cnt - 1;
}

int row_max(int **matr, int columns, int row_idx)
{
    int max = matr[row_idx][0] - 1;

    for (int j = 0; j < columns; j++)
    {
        if (matr[row_idx][j] > max)
            max = matr[row_idx][j];
    }

    return max;
}