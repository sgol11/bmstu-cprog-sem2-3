#ifndef DELETE_STUDENTS_H
#define DELETE_STUDENTS_H

#include "general_functions.h"

int delete_students(char *file_name);
int write_to_tmp(FILE *src, FILE *dst, int n);
void read_from_tmp(FILE *src, FILE *dst, int n);
double overall_avg(FILE *f, int n);
double student_avg(student *st);

#endif