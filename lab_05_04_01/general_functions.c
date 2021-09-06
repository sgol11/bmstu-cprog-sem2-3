#include "general_functions.h"

int print_students(char *file_name)
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

        for (int i = 0; i < n; i++)
        {
            student st;
            fread(&st, sizeof(student), 1, file);
            print_one_student(&st);
        }
    }

    fclose(file);

    return code;
}

void print_one_student(student *st)
{
    printf("%s\n%s\n%u %u %u %u\n", st->surname, st->name, 
    st->marks[0], st->marks[1], st->marks[2], st->marks[3]);
}

int count_elems(FILE *f)
{
    int size = 0;
    if (fseek(f, 0, SEEK_END))
        size = -1;
    else
    {
        size = ftell(f) / sizeof(student);
        if (ftell(f) < 0)
            size = -1;
    }
    rewind(f);

    return size;
}

void get_student(FILE *f, int i, student *st)
{
    fseek(f, i * sizeof(student), SEEK_SET);
    fread(st, sizeof(student), 1, f);
}

void put_student(FILE *file, int pos, student *st)
{
    fseek(file, pos * sizeof(student), SEEK_SET);
    fwrite(st, sizeof(student), 1, file);
}

int check_str(FILE *f)
{
    int code = OK;

    int n = count_elems(f);
    
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            student st;
            get_student(f, i, &st);

            if (strlen(st.surname) > MAX_SURNAME_SIZE)
                code = ERR_STR_LEN;
            if (strlen(st.name) > MAX_SURNAME_SIZE)
                code = ERR_STR_LEN;
        }
    }

    return code;
}