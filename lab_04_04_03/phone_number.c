#include "phone_number.h"

// [+country_code](DDD)-DDD-DD-DD

int processing_string(char *str)
{
    int result = 0;
    int first = 1;
    while (*str && !result)
    {
        result = check_number(str, first);
        str++;
        first = 0;
    }
    return result;
}

int check_number(char *str, int first)
{
    int i = 0, res = 1;

    check_first_space(str, &i, first, &res);

    check_sym(str, &i, '+', &res);

    if (res)
        check_variable_dig_num(str, &i, &res);
    else
    {
        res = 1;
        i--;
        check_first_space(str, &i, first, &res);
    }
    
    check_sym(str, &i, '(', &res);

    check_certain_dig_num(str, &i, 3, &res);
    
    check_sym(str, &i, ')', &res);
    check_sym(str, &i, '-', &res);

    check_certain_dig_num(str, &i, 3, &res);
    
    check_sym(str, &i, '-', &res);

    check_certain_dig_num(str, &i, 2, &res);

    check_sym(str, &i, '-', &res);

    check_certain_dig_num(str, &i, 2, &res);
    
    if (res)
        if (str[i] && str[i] != ' ' && str[i] != '\t')
            res = 0;

    return res;
}

void check_first_space(char *str, int *idx, int first, int *res)
{
    if (str[*idx] == ' ' || str[*idx] == '\t')
        *idx = *idx + 1;
    else if (!first)
        *res = 0;
}

void check_sym(char *str, int *idx, char sym, int *res)
{
    if (*res)
    {
        if (str[*idx] != sym)
            *res = 0;

        *idx = *idx + 1;
    }
}

void check_variable_dig_num(char *str, int *idx, int *res)
{
    if (*res)
    {
        int prev_idx = *idx;

        while (str[*idx] >= '0' && str[*idx] <= '9')
            *idx = *idx + 1;
        
        if (*idx == prev_idx)
            *res = 0;
    }
}

void check_certain_dig_num(char *str, int *idx, int n, int *res)
{
    if (*res)
    {
        int prev_idx = *idx;

        while (str[*idx] >= '0' && str[*idx] <= '9')
            *idx = *idx + 1;

        if ((*idx - prev_idx) != n)
            *res = 0;
    }
}
