#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#include <stdio.h>
#include <string.h>

#define OK 0
#define ERR_ARG 53
#define ERR_NO_ELEMENTS 54
#define ERR_NO_FILE 55
#define ERR_STR_LEN 56

#define MAX_SURNAME_SIZE 25
#define MAX_NAME_SIZE 10
#define MARKS_CNT 4

typedef struct
{
    char surname[MAX_SURNAME_SIZE + 1];
    char name[MAX_NAME_SIZE + 1];
    unsigned int marks[MARKS_CNT];
} student;

int print_students(char *file_name);
void print_one_student(student *st);
int check_str(FILE *f);
int count_elems(FILE *f);
void get_student(FILE *f, int i, student *st);
void put_student(FILE *file, int pos, student *st);

#endif