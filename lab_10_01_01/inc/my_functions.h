#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#include "main.h"
#include "errors.h"

#define BUF_SIZE 10

int my_getline(char **lineptr, int *n, FILE *stream);
int my_getnum(FILE *file, int *rc);

#endif