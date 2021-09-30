#ifndef __INPUT__H__
#define __INPUT__H__

#include "main.h"

int number_of_elements(char *file_name);
int fill_array(char *file_name, int *arr, int num);
void free_init_arr(int **arr);

#endif