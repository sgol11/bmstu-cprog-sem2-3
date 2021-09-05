/**
 * Назначение программы: обмен местами элементов из
 * указанной области
 */

#include <stdio.h>
#include <math.h>

#define N 10
#define M 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_NOT_SQUARE -3

void transform(int *buf, int **matr, int n, int m);
int scan(int **matr, int *n, int *m);
void swap_columns(int **matr, int n);
void swap_numbers(int *a, int *b);
void print_matrix(int **matr, int n);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N][M] = { { 0 }, { 0 } };
    int *new_a[N];

    int n = 0, m = 0;
    int error_code = OK;

    transform(*a, new_a, N, M);
    error_code = scan(new_a, &n, &m);

    if (error_code == OK)
    {
        swap_columns(new_a, n);
        printf("The resulting matrix: \n");
        print_matrix(new_a, n);
    }

    print_error(error_code);

    return error_code;
}

void transform(int *buf, int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        matr[i] = buf + i * m;
}

int scan(int **matr, int *n, int *m)
{
    int error = OK, p1 = 0, p2 = 0;

    printf("Enter the number of lines: ");
    p1 = scanf("%d", n);
    printf("Enter the number of columns: ");
    p2 = scanf("%d", m);

    if (p1 != 1 || p2 != 1)
        error = ERR_INPUT;
    else if (*n <= 0 || *m <= 0 || *n > N || *m > M)
        error = ERR_RANGE;
    else if (*n != *m)
        error = ERR_NOT_SQUARE;
    else
    {
        printf("Enter array elements: ");
        for (int i = 0; i < *n; i++)
        {
            for (int j = 0; j < *m; j++)
            {
                p1 = scanf("%d", matr[i] + j);
                if (p1 != 1)
                    error = ERR_INPUT;
            }
        }
    }

    return error;
}

void swap_columns(int **matr, int n)
{
    int k = 1;
    int middle = (n % 2 == 0) ? (n / 2 - 1) : (n / 2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            swap_numbers(matr[i] + j, matr[i] + n - j - 1);

        if (i != middle || n % 2 != 0)
            k += (i < middle) ? 1 : -1;
    }
}

void swap_numbers(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_matrix(int **matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", matr[i][j]);
        printf("\n");
    }
}

void print_error(int code)
{
    switch (code)
    {
        case ERR_INPUT:
            printf("Error: incorrect input\n");
            break;
        case ERR_RANGE:
            printf("Error: number of rows or columns is out of range");
            break;
        case ERR_NOT_SQUARE:
            printf("Error: square matrix should have the "
                "same number of rows and columns");
            break;
        default:
            break;
    }
}
