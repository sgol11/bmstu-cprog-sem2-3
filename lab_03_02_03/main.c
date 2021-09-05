/**
 * Назначение программы: удаление из матрицы всех столбцов,
 * содержащих по крайней мере одно число, в записи которого
 * встречается заданная цифра
 */

#include <stdio.h>
#include <math.h>

#define N 10
#define M 10
#define OK 0
#define ERR_INPUT 1
#define ERR_SIZE_RANGE 2
#define ERR_DIGIT_RANGE 3
#define ERR_EMPTY 4

void transform(int *buf, int **matr, int n, int m);
int scan(int **matr, int *n, int *m, int *digit);

int delete_columns(int **matr, int n, int *m, int dig);
int digit_in_column(int **matr, int n, int col_idx, int dig);
int digit_in_num(int num, int dig);
void shift_left(int **matr, int n, int m, int idx);

void print_matrix(int **matr, int n, int m);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N][M] = { { 0 }, { 0 } };
    int *new_a[N];

    int n = 0, m = 0;
    int digit = 0;
    int error_code = OK;

    transform(*a, new_a, N, M);
    error_code = scan(new_a, &n, &m, &digit);

    if (error_code == OK)
    {
        error_code = delete_columns(new_a, n, &m, digit);
        if (error_code == OK)
        {
            printf("The resulting matrix: \n");
            print_matrix(new_a, n, m);
        }
    }

    print_error(error_code);

    return error_code;
}

void transform(int *buf, int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        matr[i] = buf + i * m;
}

int scan(int **matr, int *n, int *m, int *digit)
{
    int error = OK, p = 0;

    printf("Enter the numbers of rows and columns: ");
    p = scanf("%d%d", n, m);

    if (p != 2)
        error = ERR_INPUT;
    else if (*n <= 0 || *m <= 0 || *n > N || *m > M)
        error = ERR_SIZE_RANGE;
    else
    {
        printf("Enter array elements: \n");
        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *m; j++)
            {
                p = scanf("%d", matr[i] + j);
                if (p != 1)
                    error = ERR_INPUT;
            }

        if (error == OK)
        {
            printf("Enter the digit: ");
            p = scanf("%d", digit);
            if (p != 1)
                error = ERR_INPUT;
            else if (*digit < 0 || *digit > 9)
                error = ERR_DIGIT_RANGE;
        }
    }

    return error;
}

int delete_columns(int **matr, int n, int *m, int dig)
{
    int err_code = OK;

    for (int j = 0; j < *m; j++)
    {
        if (digit_in_column(matr, n, j, dig))
        {
            shift_left(matr, n, *m, j);
            *m -= 1;
            j--;
        }
    }

    if (*m == 0)
        err_code = ERR_EMPTY;

    return err_code;
}

int digit_in_column(int **matr, int n, int col_idx, int dig)
{
    int check_digit = 0;

    for (int i = 0; i < n; i++)
        if (digit_in_num(matr[i][col_idx], dig))
            check_digit = 1;

    return check_digit;
}

int digit_in_num(int num, int dig)
{
    int result = 0;

    if (num < 0)
        num *= (-1);
    else if (num == 0 && dig == 0)
        result = 1;

    while (num > 0)
    {
        if (num % 10 == dig)
            result = 1;
        num /= 10;
    }

    return result;
}

void shift_left(int **matr, int n, int m, int idx)
{
    for (int j = idx; j < m - 1; j++)
        for (int i = 0; i < n; i++)
            matr[i][j] = matr[i][j + 1];
}

void print_matrix(int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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
        case ERR_SIZE_RANGE:
            printf("Error: number of rows or columns is out of range");
            break;
        case ERR_DIGIT_RANGE:
            printf("Error: wrong range of digit");
            break;
        case ERR_EMPTY:
            printf("Error: resulting matrix is empty");
            break;
        default:
            break;
    }
}
