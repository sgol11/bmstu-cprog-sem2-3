#ifndef __ARRAY__H__
#define __ARRAY__H__

#include <stdio.h>
#include <math.h>

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

ARR_DLL void ARR_DECL fill_arr_with_prime_numbers(int *array, int size);
int is_prime(int num);
ARR_DLL int ARR_DECL arr_transfer(int *array_1, int *array_2, int size, int num);

#endif