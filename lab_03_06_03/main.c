/**
 * Назначение программы: заполнение квадратной матрицы
 * по спирали против часовой стрелки
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
int scan(int *n, int *m);

void fill_matrix(int **matr, int n, int m);

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
    error_code = scan(&n, &m);

    if (error_code == OK)
    {
        fill_matrix(new_a, n, m);
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

int scan(int *n, int *m)
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

    return error;
}

void fill_matrix(int **matr, int n, int m)
{
    int left = 0, right = 0, bottom = 0, top = 0;

    int k = 1;
    int i = 0;
    int j = 0;

    while (k <= n * m)
    {
        matr[i][j] = k;

        // left border
        if (j == left && i < n - bottom - 1)
            i++;
        // bottom border
        else if (i == n - bottom - 1 && j < m - right - 1)
            j++;
        // right border
        else if (j == m - right - 1 && i > top)
            i--;
        // top border
        else
            j--;

        if ((j == left + 1) && (i == top))
        {
            left++;
            right++;
            bottom++;
            top++;
        }

        k++;
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
        case ERR_NOT_SQUARE:
            printf("Error: square matrix should have the "
                "same number of rows and columns");
            break;
        default:
            break;
    }
}
