#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../inc/sort.h"

void measure_time(char *file_name, int arr_type);

int main(void)
{
    setbuf(stdout, NULL);

    measure_time("cmp/sorted.csv", 1);
    measure_time("cmp/back_sorted.csv", 2);
    measure_time("cmp/not_sorted.csv", 3);

    return 0;
}

void measure_time(char *file_name, int arr_type)
{
    clock_t begin1, begin2, end1, end2;
    double time_spent1 = 0, time_spent2 = 0;

    FILE *file = fopen(file_name, "w");
    fprintf(file, "n,mysort,qsort\n");

    for (int n = 2000; n <= 10000; n += 200)
    {
        int *arr1 = NULL, *arr2 = NULL;
        arr1 = malloc(n * sizeof(int));
        arr2 = malloc(n * sizeof(int));

        time_spent1 = 0;
        time_spent2 = 0;

        for (int cnt = 0; cnt < 10; cnt++)
        {
            switch (arr_type)
            {
                case 1:
                    for (int i = 0; i < n; i++)
                    {
                        arr1[i] = i;
                        arr2[i] = i;
                    }
                    break;
                case 2:
                    for (int i = 0; i < n; i++)
                    {
                        arr1[i] = n - i;
                        arr2[i] = n - i;
                    }
                    break;
                case 3:
                    for (int i = 0; i < n; i++)
                    {
                        arr1[i] = (i % 2 == 0) ? i : -1 * i;
                        arr2[i] = (i % 2 == 0) ? i : -1 * i;
                    }
                    break;
            }
            
            begin1 = clock();
            mysort(arr1, n, sizeof(int), compare_int);
            end1 = clock();

            begin2 = clock();
            qsort(arr2, n, sizeof(int), compare_int);
            end2 = clock();

            time_spent1 += (double)(end1 - begin1) / CLOCKS_PER_SEC; 
            time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC; 

            printf("n = %d : %d measure\n", n, cnt + 1);
        }

        time_spent1 /= 10; 
        time_spent2 /= 10; 
            
        fprintf(file, "%d,", n);
        fprintf(file, "%lf,", time_spent1);
        fprintf(file, "%lf", time_spent2);
        fprintf(file, "\n");

        free(arr1);
        free(arr2);
    }

    fclose(file);
}