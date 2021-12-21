#ifndef __INPUT__H__
#define __INPUT__H__

#include "main.h"

#ifdef INPUT_EXPORTS
#define INPUT_DLL __declspec(dllexport)
#else
#define INPUT_DLL __declspec(dllimport)
#endif

#define INPUT_DECL __cdecl

INPUT_DLL int INPUT_DECL number_of_elements_from_file(char *file_name);
INPUT_DLL int INPUT_DECL fill_array_from_file(char *file_name, int *arr, int num);

#endif