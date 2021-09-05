/**
 * Назначение программы: циклический сдвиг влево на 3
 * элементов с суммой цифр больше 10
 */

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10
#define ROTATIONS 3
#define MIN_DIGITS_SUM 10
#define OK 0
#define ERR_INPUT 101
#define ERR_RANGE 102
#define ERR_NO_REQUIRED_NUMBERS 103

void transform(int *buf, int **matr, int n, int m);
int scan(int **matr, int *n, int *m);

int change_matr(int **matr, int n, int m);
int copy_to_array(int **matr, int n, int m, int *a);
int digits_sum(int num);
void rotate_left(int *a, int size, int rotate_count);
void shift_left(int *a, int size);
void swap_numbers(int *a, int *b);
void copy_to_matrix(int **matr, int n, int m, int *a);

void print_matrix(int **matr, int n, int m);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a[MAX_SIZE][MAX_SIZE] = { { 0 }, { 0 } };
    int *new_a[MAX_SIZE];

    int n = 0, m = 0;
    int error_code = OK;

    transform(*a, new_a, MAX_SIZE, MAX_SIZE);
    error_code = scan(new_a, &n, &m);

    if (error_code == OK)
    {
        error_code = change_matr(new_a, n, m);
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

int scan(int **matr, int *n, int *m)
{
    int error = OK, p = 0;

    printf("Enter the numbers of rows and columns: ");
    p = scanf("%d%d", n, m);

    if (p != 2)
        error = ERR_INPUT;
    else if (*n <= 0 || *m <= 0 || *n > MAX_SIZE || *m > MAX_SIZE)
        error = ERR_RANGE;
    else
    {
        printf("Enter array elements: \n");
        for (int i = 0; i < *n; i++)
        {
            for (int j = 0; j < *m; j++)
            {
                p = scanf("%d", matr[i] + j);
                if (p != 1)
                    error = ERR_INPUT;
            }
        }
    }

    return error;
}

int change_matr(int **matr, int n, int m)
{
    int tmp_arr[MAX_SIZE * MAX_SIZE] = { 0 };
    int res = OK;

    res = copy_to_array(matr, n, m, tmp_arr);

    if (res != ERR_NO_REQUIRED_NUMBERS)
    {
        rotate_left(tmp_arr, res, ROTATIONS);
        copy_to_matrix(matr, n, m, tmp_arr);
        res = OK;
    }

    return res;
}

void print_array(int *a, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int copy_to_array(int **matr, int n, int m, int *a)
{
    int k = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (digits_sum(matr[i][j]) > MIN_DIGITS_SUM)
            {
                a[k] = matr[i][j];
                k++;
            }
        }

    if (k == 0)
        k = ERR_NO_REQUIRED_NUMBERS;

    return k;
}

int digits_sum(int num)
{
    int sum = 0;

    if (num < 0)
        num *= -1;

    while (num > 0)
    {
        sum += (num % 10);
        num /= 10;
    }

    return sum;
}

void rotate_left(int *a, int size, int rotate_count)
{
    for (int i = 0; i < rotate_count; i++)
        shift_left(a, size);
}

void shift_left(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
        swap_numbers(a + i, a + i + 1);
}

void swap_numbers(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void copy_to_matrix(int **matr, int n, int m, int *a)
{
    int k = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (digits_sum(matr[i][j]) > 10)
            {
                matr[i][j] = a[k];
                k++;
            }
        }
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
        case ERR_RANGE:
            printf("Error: number of rows or columns is out of range");
            break;
        case ERR_NO_REQUIRED_NUMBERS:
            printf("Error: no elements with the sum of digits "
                "greater than ten");
            break;
        default:
            break;
    }
}
