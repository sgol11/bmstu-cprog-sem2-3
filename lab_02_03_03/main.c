/**
 * Назначение программы: вставка после каждого положительного
 * элемента массива реверса этого элемента
 */

#include <stdio.h>
#include <math.h>

#define N 20
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define ERR_NO_POSITIVE -3

int scan(int *a, int *n);
int insert_reverse_numbers(int *a, int n1, int *n2);
int num_of_pos(int *a, int n);
void shift_right(int *a, int n, int idx);
int reverse_number(int num);
void print_array(int *a, int n);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N] = { 0 };
    int n1 = 0, n2 = 0;
    int error_code = OK;

    error_code = scan(a, &n1);

    if (error_code == OK)
    {
        error_code = insert_reverse_numbers(a, n1, &n2);
        if (error_code == OK)
        {
            printf("The resulting array: ");
            print_array(a, n2);
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

int insert_reverse_numbers(int *a, int n1, int *n2)
{
    int error = OK;
    int pos_num = num_of_pos(a, n1);

    *n2 = n1 + pos_num;

    for (int i = 0; i < *n2; i++)
    {
        if (a[i] > 0)
        {
            shift_right(a, *n2, i);
            a[i + 1] = reverse_number(a[i]);
            i++;
        }
    }

    if (pos_num == 0)
        error = ERR_NO_POSITIVE;

    return error;
}

int num_of_pos(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 0)
            count++;
    return count;
}

void shift_right(int *a, int n, int idx)
{
    for (int i = n - 1; i > idx; i--)
        a[i] = a[i - 1];
}

int reverse_number(int num)
{
    int new_num = 0;
    int first_null = 1;

    while (num > 0)
    {
        if (num % 10 != 0 || !first_null)
        {
            new_num = new_num * 10 + num % 10;
            first_null = 0;
        }
        num /= 10;
    }

    return new_num;
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
