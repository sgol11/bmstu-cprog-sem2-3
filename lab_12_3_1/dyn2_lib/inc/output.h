#ifndef __OUTPUT__H__
#define __OUTPUT__H__

#include "main.h"

#ifdef OUTPUT_EXPORTS
#define OUTPUT_DLL __declspec(dllexport)
#else
#define OUTPUT_DLL __declspec(dllimport)
#endif

#define OUTPUT_DECL __cdecl

OUTPUT_DLL int OUTPUT_DECL write_into_file(char *file_name, int *pb, int *pe);
void print_array(FILE *file, int *pb, int *pe);

#endif