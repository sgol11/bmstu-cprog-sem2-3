#ifndef __OUTPUT__H__
#define __OUTPUT__H__

#include "main.h"

__declspec(dllexport) int __cdecl write_into_file(char *file_name, int *pb, int *pe);
void print_array(FILE *file, int *pb, int *pe);

#endif