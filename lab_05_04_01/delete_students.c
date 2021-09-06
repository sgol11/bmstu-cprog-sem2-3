#include "delete_students.h"

int delete_students(char *file_name)
{
    int code = OK;

    FILE *file = fopen(file_name, "rb");

    if (!file)
        code = ERR_NO_FILE;
    else
        code = check_str(file);

    if (code == OK)
    {
        int n = count_elems(file);
        if (n <= 0)
            code = ERR_NO_ELEMENTS;
        else
        {
            FILE *tmp = fopen("tmp.bin", "w+b");

            int new_n = write_to_tmp(file, tmp, n);

            if (new_n == 0)
                code = ERR_NO_ELEMENTS;
            else
            {
                fclose(file);
                file = fopen(file_name, "wb");
            
                read_from_tmp(tmp, file, new_n);
            }

            fclose(tmp);
        }
    }

    fclose(file);

    return code;
}

int write_to_tmp(FILE *src, FILE *dst, int n)
{
    double avg = overall_avg(src, n);
    int new_n = 0;

    for (int i = 0; i < n; i++)
    {
        student a;
        get_student(src, i, &a);

        if (student_avg(&a) >= avg)
        {
            fwrite(&a, sizeof(student), 1, dst);
            new_n++;
        }
    }

    return new_n;
}

void read_from_tmp(FILE *src, FILE *dst, int n)
{
    for (int i = 0; i < n; i++)
    {
        student a;
        get_student(src, i, &a);
        fwrite(&a, sizeof(student), 1, dst);
    }
}

double overall_avg(FILE *f, int n)
{
    double sum_of_avg = 0;

    for (int i = 0; i < n; i++)
    {
        student st;
        get_student(f, i, &st);
        sum_of_avg += student_avg(&st);
    }

    return sum_of_avg / n;
}

double student_avg(student *st)
{
    double sum = 0;

    for (int i = 0; i < 4; i++)
        sum += st->marks[i];

    return sum / 4;
}