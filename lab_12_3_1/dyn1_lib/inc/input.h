#ifndef __INPUT__H__
#define __INPUT__H__

#include "main.h"

__declspec(dllexport) int __cdecl number_of_elements_from_file(char *file_name);
__declspec(dllexport) int __cdecl fill_array_from_file(char *file_name, int *arr, int num);

#endif