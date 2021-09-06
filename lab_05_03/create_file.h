#ifndef CREATE_FILE_H
#define CREATE_FILE_H

#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERR_IO -1
#define NO_NUMBERS -2
#define SIZE_ERR -3
#define WRONG_ARG -4

int create_file(char *file_name, int n);

#endif