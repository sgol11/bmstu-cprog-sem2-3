#include "three_sigma_rule.h"

int three_sigma_rule(FILE *f, int *res)
{
    int code = OK;

    double expected_val = expected_value(f, &code);

    if (code == OK)
    {
        double std_dev = standard_deviation(f, expected_val, &code);
        *res = is_correct(f, expected_val, std_dev, &code);
    }

    return code;
}

double expected_value(FILE *f, int *code)
{
    fseek(f, 0, SEEK_SET);
    double num, sum = 0;
    int count = 0;

    while (*code == OK && !feof(f))
    {
        if (fscanf(f, "%lf", &num) == 1)
        {
            sum += num;
            count++;
        }
        else
            *code = ERR_WRONG_DATA;
    }

    if (*code == OK && count == 0)
        *code = ERR_NO_DATA;

    return count == 0 ? -1 : sum / count;
}

double standard_deviation(FILE *f, double arithm_mean, int *code)
{
    fseek(f, 0, SEEK_SET);
    double num, sum = 0;
    int count = 0;

    while (*code == OK && !feof(f))
    {
        if (fscanf(f, "%lf", &num) == 1)
        {
            sum += (num - arithm_mean) * (num - arithm_mean);
            count++;
        }
        else
            *code = ERR_WRONG_DATA;
    }

    if (*code == OK && count == 0)
        *code = ERR_NO_DATA;

    return count == 0 ? -1 : sqrt(sum / count);
}

int is_correct(FILE *f, double avg, double sigma, int *code)
{
    fseek(f, 0, SEEK_SET);
    double num;
    int res = 1;

    double min_border = avg - 3 * sigma;
    double max_border = avg + 3 * sigma;
    
    while (*code == OK && !feof(f))
    {
        if (fscanf(f, "%lf", &num) == 1)
        {
            if (!(num > min_border && num < max_border))
                res = 0;
        }
        else
            *code = ERR_WRONG_DATA;
    }

    return res;
}