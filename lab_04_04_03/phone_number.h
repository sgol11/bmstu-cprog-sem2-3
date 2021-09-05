#include <stdio.h>
#include <string.h>

#define MAX_STLEN 256

#define OK 0
#define BUFFER_OVERFLOW 1

int read_line(char *str, int n);
int processing_string(char *str);
int check_number(char *str, int first);
void check_first_space(char *str, int *idx, int first, int *res);
void check_variable_dig_num(char *str, int *idx, int *res);
void check_sym(char *str, int *idx, char sym, int *res);
void check_certain_dig_num(char *str, int *idx, int n, int *res);

// void print_error(int code);