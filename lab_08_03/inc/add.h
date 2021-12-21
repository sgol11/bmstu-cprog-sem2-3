#ifndef __ADD__H__
#define __ADD__H__

#include "main.h"
#include "memory_work.h"

int one_size_by_adding(matrix_t *a, matrix_t *b);
int form_matrix_by_adding(matrix_t *matr, int final_size);
int column_avg(int **matr, int rows, int column_idx);
int row_max(int **matr, int columns, int row_idx);

#endif