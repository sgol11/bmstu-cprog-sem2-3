#ifndef __FILTER__H__
#define __FILTER__H__

#include "main.h"

#define ERR_NO_FILE -2
#define ERR_EMPTY_FILE -3
#define ERR_INPUT -4
#define ERR_MEMORY -5

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void get_last_neg(const int *pb_src, const int *pe_src, const int **last_neg);
void read_to_last_neg(const int *pb_src, const int *last_neg, int *arr);
void free_new_arr(int **pb, int **pe);

#endif