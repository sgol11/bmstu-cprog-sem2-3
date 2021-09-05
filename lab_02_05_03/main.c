/**
 * Назначение программы: нахождение минимального произведения
 * двух соседних чисел в массиве с использованием указателей
 */

#include <stdio.h>
#include <math.h>

#define N 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_ONE_ELEMENT -3

int scan(int *a, int *n);
int computation(int *pb, int *pe);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N] = { 0 };
    int n = 0;
    int error_code = OK;
    int result = 0;

    error_code = scan(a, &n);

    if (error_code == OK)
    {
        result = computation(a, a + n);
        printf("The result: %d\n", result);
    }

    print_error(error_code);

    return error_code;
}

int scan(int *a, int *n)
{
    int error = OK, p = 0;

    printf("Enter the number of elements: ");
    p = scanf("%d", n);

    int *pb = a, *pe = a + *n;

    if (p != 1)
        error = ERR_INPUT;
    else if (pb >= pe)
        error = ERR_RANGE;
    else if (pe - pb == 1)
        error = ERR_ONE_ELEMENT;
    else
    {
        printf("Enter array elements: ");
        for (int *pcur = pb; pcur < pe; pcur++)
        {
            p = scanf("%d", pcur);
            if (p != 1)
                error = ERR_INPUT;
        }
    }

    return error;
}

int computation(int *pb, int *pe)
{
    int min = (*pb) * (*(pb + 1));

    for (int *pcur = pb + 2; pcur < pe; pcur++)
    {
        if (*(pcur - 1) * (*pcur) < min)
            min = *(pcur - 1) * (*pcur);
    }

    return min;
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
        case ERR_ONE_ELEMENT:
            printf("Error: one element in array (you need at least two)\n");
            break;
        default:
            break;
    }
}
