/**
 * Назначение программы: сортировка строк по убыванию
 * их наименьших элементов
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
void sort_lines(int **matr, int n, int m);
int max_line(int **matr, int n, int m, int idx);
int min_in_line(int *line, int m);
void move_lines(int **matr, int idx, int i_max);
void print_matrix(int **matr, int n, int m);
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
        sort_lines(new_a, n, m);
        printf("The resulting matrix: \n");
        print_matrix(new_a, n, m);
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

void sort_lines(int **matr, int n, int m)
{
    for (int i = 0; i < n - 1; i++)
    {
        int i_max = max_line(matr, n, m, i);

        move_lines(matr, i, i_max);
    }
}

int max_line(int **matr, int n, int m, int idx)
{
    int i_max = idx;
    int max = min_in_line(matr[idx], m);

    for (int i = idx + 1 ; i < n; i++)
    {
        int current = min_in_line(matr[i], m);
        if (current > max)
        {
            max = current;
            i_max = i;
        }
    }

    return i_max;
}

int min_in_line(int *line, int m)
{
    int min = *line;

    for (int i = 1; i < m; i++)
        if (line[i] < min)
            min = line[i];

    return min;
}

void move_lines(int **matr, int idx, int i_max)
{
    int *tmp = matr[i_max];

    for (int k = i_max; k > idx; k--)
        matr[k] = matr[k - 1];

    matr[idx] = tmp;
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
        default:
            break;
    }
}
