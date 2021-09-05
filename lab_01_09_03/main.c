/**
Назначение программы: вычисление значения функции
(ввод до первого отрицательного элемента)
 */

#include <stdio.h>
#include <math.h>

double input_processing();
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    double res, g = -1;
    int error_code = 0;

    res = input_processing();

    if (res < 0)
        error_code = (int) res * (-1);
    if (error_code == 0)
        g = exp(res);

    if (error_code == 0)
        printf("Result: %.6lf\n", g);
    else
        print_error(error_code);

    return error_code;
}

double input_processing()
{
    double x, res = 1.0;
    int n = 1;
    int rc;

    printf("Input sequence: ");

    rc = scanf("%lf", &x);
    if (rc != 1)
        res = -1.0;
    else if (x < 0)
        res = -2.0;
    else
    {
        while (x >= 0)
        {
            res /= (x + n);
            n += 1;

            rc = scanf("%lf", &x);
            if (rc != 1)
            {
                res = -1.0;
                break;
            }
        }
    }

    return res;
}

void print_error(int code)
{
    switch (code)
    {
        case 1:
            printf("Error: input error\n");
            break;
        case 2:
            printf("Error: empty sequence\n");
            break;
        default:
            break;
    }
}
