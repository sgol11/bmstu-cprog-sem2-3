#include "sort_students.h"

int sort_students(char *file_name)
{
    int code = OK;

    FILE *file = fopen(file_name, "r+b");

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
            for (int j = 0; j < n - 1 - i; j++)
            {
                student s1, s2;
                get_student(file, j, &s1);
                get_student(file, j + 1, &s2);

                char *srn1 = s1.surname;
                char *srn2 = s2.surname;

                if (strcmp(srn1, srn2) > 0)
                    swap(file, j, j + 1);
                else if (strcmp(srn1, srn2) == 0)
                {
                    char *n1 = s1.name;
                    char *n2 = s2.name;

                    if (strcmp(n1, n2) > 0)
                        swap(file, j, j + 1);
                }
            }
            
        fclose(file);
    }

    return code;
}

void swap(FILE *f, int pos_1, int pos_2)
{
    student a, b;
    get_student(f, pos_1, &a);
    get_student(f, pos_2, &b);
    
    put_student(f, pos_1, &b);
    put_student(f, pos_2, &a);
}