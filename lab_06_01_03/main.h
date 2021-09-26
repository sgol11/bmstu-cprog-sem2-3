#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERR_ARG 1

#define MAX_ARR_SIZE 15
#define MAX_NAME_SIZE 25

typedef struct
{
    char name[MAX_NAME_SIZE + 1];
    int price;
} product;

#endif