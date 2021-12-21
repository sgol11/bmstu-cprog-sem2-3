#ifndef __MEMORY__H__
#define __MEMORY__H__

#include "main.h"

void init_matrix(matrix_t *matr);
int **allocate_matrix(int n, int m);
void free_matrix(int **ptrs, int n);
int delete_rows_memory(matrix_t *matr, int init_rows);
int delete_columns_memory(matrix_t *matr);
int add_rows_memory(matrix_t *matr, int final_rows);
int add_columns_memory(matrix_t *matr, int final_columns);

#endif