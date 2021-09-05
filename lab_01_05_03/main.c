/**
Назначение программы: нахождение наибольшего
общего делителя двух натуральных чисел
 */

#include <stdio.h>

int nod(int x, int y);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a, b;
    int rc, error_code = 0;
    int res = -1;

    printf("Input numbers: ");
    rc = scanf("%d%d", &a, &b);

    if (rc != 2)
        error_code = 1;
    else if (a <= 0 || b <= 0)
        error_code = 2;
    else
        res = nod(a, b);

    if (error_code == 0)
        printf("NOD of numbers = %d\n", res);
    else
        print_error(error_code);

    return error_code;
}

int nod(int x, int y)
{
    int z;
    while (y != 0)
    {
        z = x % y;
        x = y;
        y = z;
    }
    return x;
}

void print_error(int code)
{
    switch (code)
    {
        case 1:
            printf("Error: input error\n");
            break;
        case 2:
            printf("Error: negative number\n");
            break;
        default:
            break;
    }
}
