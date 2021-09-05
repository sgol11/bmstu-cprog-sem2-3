/**
Назначение программы: расчет суммы бесконечного
ряда, сравнение полученного значения с функцией
арктангенса
 */

#include <stdio.h>
#include <math.h>

double s(double x, double eps);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    double x, eps;
    int rc, error_code = 0;
    double sum = -1, func = -1, abs_err = -1, rel_err = -1;

    printf("Input x and eps: ");
    rc = scanf("%lf%lf", &x, &eps);

    if (rc != 2)
        error_code = 1;
    else if (x > 1 || x < -1 || fabs(x) < 1e-7)
        error_code = 2;
    else if (eps <= 0 || eps > 1)
        error_code = 3;
    else
    {
        sum = s(x, eps);
        func = atan(x);
        abs_err = fabs(func - sum);
        rel_err = fabs(func - sum) / fabs(func);
    }

    if (error_code == 0)
        printf("Results: %.6lf %.6lf %.6lf %.6lf\n",
        sum, func, abs_err, rel_err);
    else
        print_error(error_code);

    return error_code;
}

double s(double x, double eps)
{
    double t = x, s = 0;
    int n = 1;

    while (fabs(t) >= eps)
    {
        s += t;
        n += 2;
        t *= -(x * x) * (n - 2) / n;
    }

    return s;
}

void print_error(int code)
{
    switch (code)
    {
        case 1:
            printf("Error: input error\n");
            break;
        case 2:
            printf("Error: invalid x range\n");
            break;
        case 3:
            printf("Error: invalid eps range\n");
            break;
        default:
            break;
    }
}
