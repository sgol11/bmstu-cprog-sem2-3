/**
 * Назначение программы: получение по матрице одномерного
 * массива, в котором k-ый элемент имеет значение 1, если
 * k-ая строка матрицы образует монотонную последовательность,
 * и 0 в противном случае
 */

#include <stdio.h>
#include <math.h>

#define N 10
#define M 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2

void transform(int *buf, int **matr, int n, int m);
int scan(int **matr, int *n, int *m);
void fill_array_b(int *b, int **matr, int n, int m);
int monotonic_sequence(int *a, int m);
void print_array(int *b, int n);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N][M] = { { 0 }, { 0 } };
    int *new_a[N];

    int b[N] = { 0 };
    int n = 0, m = 0;
    int error_code = OK;

    transform(*a, new_a, N, M);
    error_code = scan(new_a, &n, &m);

    if (error_code == OK)
    {
        fill_array_b(b, new_a, n, m);
        printf("The resulting array: ");
        print_array(b, n);
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

void fill_array_b(int *b, int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        b[i] = monotonic_sequence(matr[i], m);
}

int monotonic_sequence(int *a, int m)
{
    int prev = 0, current = 0;
    int result = 1;

    if (m == 1)
        result = 0;
    else
    {
        prev = a[1] - a[0];

        for (int i = 2; i < m; i++)
        {
            current = a[i] - a[i - 1];
            if (prev * current < 0)
                result = 0;
            prev = current;
        }
    }

    return result;
}

void print_array(int *b, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");
}

void print_error(int code)
{
    switch (code)
    {
        case ERR_INPUT:
            printf("Error: incorrect input\n");
            break;
        case ERR_RANGE:
            printf("Error: number of rows or columns is out of range\n");
            break;
        default:
            break;
    }
}
