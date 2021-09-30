#ifndef __SORT__H__
#define __SORT__H__

#include "main.h"

int mysort(void *arr, size_t num, size_t size, int (*comparator)(const void *, const void *));
void swap(void *cur, void *next, int size);
int compare_int(const void *a, const void *b);

#endif