/**
 * Назначение программы: формирование нового массива из
 * элементов, являющихся числами Армстронга, исходного массива.
 *
 * Пояснение:
 * Натуральное десятичное N-значное число называется числом
 * Армстронга, если сумма его цифр, возведенных в степень N,
 * равна самому числу.
 *
 * Пример: 153 = 1^3 + 5^3 + 3^3 ; 1634 = 1^4 + 6^4 + 3^4 + 4^4.
 */

#include <stdio.h>
#include <math.h>

#define N 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_NO_ARMSTRONG_NUMBERS -3

int scan(int *a, int *n);
int is_armstrong_number(int num);
int armstrong_numbers_array(int *a, int n1, int *b, int *n2);
void print_array(int *b, int n);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N] = { 0 }, b[N] = { 0 };
    int n1 = 0, n2 = 0;
    int error_code = OK;

    error_code = scan(a, &n1);

    if (error_code == OK)
    {
        error_code = armstrong_numbers_array(a, n1, b, &n2);
        if (error_code == OK)
        {
            printf("Array of Armstrong numbers: ");
            print_array(b, n2);
        }
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

int armstrong_numbers_array(int *a, int n1, int *b, int *n2)
{
    int j = 0;
    int error = OK;

    for (int i = 0; i < n1; i++)
    {
        if (is_armstrong_number(a[i]))
            b[j++] = a[i];
    }
    *n2 = j;

    if (j == 0)
        error = ERR_NO_ARMSTRONG_NUMBERS;

    return error;
}

int is_armstrong_number(int num)
{
    int res = 0;
    int original_num = num;
    int sum_powers_digits = 0, count = 0;

    for (int tmp = num; tmp != 0; tmp = tmp / 10)
        count++;

    while (num > 0)
    {
        sum_powers_digits += (int)pow(num % 10, count);
        num /= 10;
    }

    if (original_num == sum_powers_digits)
        res = 1;

    return res;
}

void print_array(int *b, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
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
        case ERR_NO_ARMSTRONG_NUMBERS:
            printf("Error: no Armstrong numbers in array\n");
            break;
        default:
            break;
    }
}
