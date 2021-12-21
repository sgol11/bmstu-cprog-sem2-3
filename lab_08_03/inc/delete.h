#ifndef __DELETE__H__
#define __DELETE__H__

#include "main.h"
#include "memory_work.h"

int square_matrix_by_removing(matrix_t *matr);
int first_max_by_columns_idx(matrix_t *matr, int axis);
int shift_rows(matrix_t *matr, int row_idx);
int shift_columns(matrix_t *matr, int col_idx);

#endif