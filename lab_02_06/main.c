/**
 * Назначение программы: вычисление времени обработки
 * массива разными способами
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#define N 10000
#define OK 0

void form_array(int *a, int n);
int process_1(int *a, int n);
int process_2(int *a, int n);
int process_3(int *pb, int *pe);
double calc_time(int *array, int rep_num, int size, int process);
void print_result(int rep_number, int size, double t1, double t2, double t3);

int main(void)
{
    setbuf(stdout, NULL);
    int error_code = OK;
    int a[N] = { 0 };
    int size[4] = { 50, 500, 5000, 10000 };
    int rep_num[5] = { 50, 100, 500, 1000, 5000 };
    double time1 = 0.0, time2 = 0.0, time3 = 0.0;

    for (int i = 0; i < 4; i++)
    {
        form_array(a, size[i]);

        for (int j = 0; j < 5; j++)
        {
            time1 = calc_time(a, rep_num[j], size[i], 1);
            time2 = calc_time(a, rep_num[j], size[i], 2);
            time3 = calc_time(a, rep_num[j], size[i], 3);

            print_result(rep_num[j], size[i], time1, time2, time3);
        }
    }

    return error_code;
}

void form_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand();
}

double calc_time(int *array, int rep_num, int size, int process)
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time, sum = 0, max_time = 0, min_time = INT_MAX;

    for (int i = 0; i < rep_num; i++)
    {
        gettimeofday(&tv_start, NULL);
        switch (process)
        {
            case 1:
                process_1(array, size);
            case 2:
                process_2(array, size);
            case 3:
                process_3(array, array + size);
        }
        gettimeofday(&tv_stop, NULL);

        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
        (tv_stop.tv_usec - tv_start.tv_usec);

        max_time = (max_time > elapsed_time) ? max_time : elapsed_time;
        min_time = (min_time < elapsed_time) ? min_time : elapsed_time;

        sum += elapsed_time;
    }

    return (double)(sum - max_time - min_time) / (rep_num - 2);
}

int process_1(int *a, int n)
{
    int min = a[0] * a[1];

    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] * a[i] < min)
            min = a[i - 1] * a[i];
    }

    return min;
}

int process_2(int *a, int n)
{
    int min = *a * (*(a + 1));

    for (int i = 2; i < n; i++)
    {
        if (*(a + i - 1) * (*(a + i)) < min)
            min = *(a + i - 1) * (*(a + i));
    }

    return min;
}

int process_3(int *pb, int *pe)
{
    int min = (*pb) * (*(pb + 1));

    for (int *pcur = pb + 2; pcur < pe; pcur++)
    {
        if (*(pcur - 1) * (*pcur) < min)
            min = *(pcur - 1) * (*pcur);
    }

    return min;
}

void print_result(int rep_number, int size, double t1, double t2, double t3)
{
    printf("| %d | %d | %.6lf | %.6lf | %.6lf |", rep_number, size, t1, t2, t3);
    printf("\n");
}
