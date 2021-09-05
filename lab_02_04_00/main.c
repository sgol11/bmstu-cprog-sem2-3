/**
 * Назначение программы: сортировка элементов массива
 * методом пузырька (+ввод по концевому признаку)
 */

#include <stdio.h>
#include <math.h>

#define N 10
#define OK 0
#define ERR_RANGE -1
#define WAR_OVERFLOW 100

int scan(int *a, int *n);
void bubble_sort(int *a, int n);
void swap(int *a, int *b);
void print_array(int *a, int n);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N] = { 0 };
    int n = 0;
    int error_code = OK;

    error_code = scan(a, &n);

    if (error_code != ERR_RANGE)
    {
        bubble_sort(a, n);
        printf("Sorted array: ");
        print_array(a, n);
    }

    print_error(error_code);

    return error_code;
}

int scan(int *a, int *n)
{
    int error = OK, p = 0;
    int i = 0;

    printf("Enter array elements: ");

    p = scanf("%d", a);
    if (p != 1)
        error = ERR_RANGE;

    while (p == 1 && error == OK)
    {
        i++;
        if (i < N)
            p = scanf("%d", a + i);
        else
        {
            p = scanf("%d", a + i);
            if (p == 1)
                error = WAR_OVERFLOW;
        }
    }

    *n = i;

    return error;
}

void bubble_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a + j, a + j + 1);
        }
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void print_error(int code)
{
    switch (code)
    {
        case ERR_RANGE:
            printf("Error: empty array\n");
            break;
        case WAR_OVERFLOW:
            printf("Warning: more than ten elements entered\n");
            break;
        default:
            break;
    }
}
