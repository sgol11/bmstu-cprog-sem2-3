#ifndef __SORT__H__
#define __SORT__H__

#include "main.h"

#ifdef SORT_EXPORTS
#define SORT_DLL __declspec(dllexport)
#else
#define SORT_DLL __declspec(dllimport)
#endif

#define SORT_DECL __cdecl

SORT_DLL int SORT_DECL mysort(void *arr, size_t num, size_t size, int (*comparator)(const void *, const void *));
void swap(void *cur, void *next, int size);

#endif