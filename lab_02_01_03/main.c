/**
 * Назначение программы: вычисление среднего
 * геометрического положительных элементов массива
 */

#include <stdio.h>
#include <math.h>

#define N 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_NO_POSITIVE -3

int scan(int *a, int *n);
double geometric_mean(int *a, int n);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N] = { 0 };
    int n = 0;
    double result = 0;
    int error_code = OK;

    error_code = scan(a, &n);

    if (error_code == OK)
    {
        result = geometric_mean(a, n);
        if (result < 0)
            error_code = ERR_NO_POSITIVE;
        else
            printf("Geometric mean of positive numbers: %.6lf\n", result);
    }

    print_error(error_code);

    return error_code;
}

int scan(int *a, int *n)
{
    int error = OK, p = 0;

    printf("Enter the number of elements: ");
    p = scanf("%d", n);
    if (p != 1)
        error = ERR_INPUT;
    else if (*n <= 0)
        error = ERR_RANGE;
    else
    {
        printf("Enter array elements: ");
        for (int i = 0; i < *n; i++)
        {
            p = scanf("%d", a + i);
            if (p != 1)
                error = ERR_INPUT;
        }
    }

    return error;
}

double geometric_mean(int *a, int n)
{
    double mult = 1, res = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            mult *= a[i];
            count += 1;
        }
    }

    if (count == 0)
        res = -1;
    else
        res = pow(mult, 1 / (double)count);

    return res;
}

void print_error(int code)
{
    switch (code)
    {
        case ERR_INPUT:
            printf("Error: incorrect input\n");
            break;
        case ERR_RANGE:
            printf("Error: array size should be positive\n");
            break;
        case ERR_NO_POSITIVE:
            printf("Error: no positive elements\n");
            break;
        default:
            break;
    }
}
