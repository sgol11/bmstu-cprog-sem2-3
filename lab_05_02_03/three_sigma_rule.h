#ifndef THREE_SIGMA_RULE_H
#define THREE_SIGMA_RULE_H

#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_NO_FILE 1
#define ERR_NO_DATA 2
#define ERR_WRONG_DATA 3

int three_sigma_rule(FILE *f, int *res);
double expected_value(FILE *f, int *code);
double standard_deviation(FILE *f, double arithm_mean, int *code);
int is_correct(FILE *f, double avg, double sigma, int *code);

#endif