#ifndef __MULTI__H__
#define __MULTI__H__

#include "main.h"
#include "memory_work.h"
#include "io.h"

int calculate(matrix_t *first_matr, int first_pow, matrix_t *second_matr, 
int second_pow, matrix_t *res_matr);
int assign_multi_res(matrix_t *res, matrix_t *multiplier);
void copy_matrix(matrix_t *src, matrix_t *dst);
void make_identity_matrix(matrix_t *matr);
int multiply(matrix_t *m1, matrix_t *m2, matrix_t *res);

#endif