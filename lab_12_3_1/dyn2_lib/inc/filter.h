#ifndef __FILTER__H__
#define __FILTER__H__

#include "main.h"

#ifdef FILTER_EXPORTS
#define FILTER_DLL __declspec(dllexport)
#else
#define FILTER_DLL __declspec(dllimport)
#endif

#define FILTER_DECL __cdecl

FILTER_DLL int FILTER_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void find_last_neg(const int *pb_src, const int *pe_src, const int **last_neg);
void copy_to_last_neg(const int *pb_src, const int *last_neg, int *arr);

#endif