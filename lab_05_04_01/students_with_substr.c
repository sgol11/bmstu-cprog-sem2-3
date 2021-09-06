#include "students_with_substr.h"

int students_with_substr(char *file_src, char *file_dst, char *substr)
{
    int code = OK;

    FILE *f1 = fopen(file_src, "rb");
    FILE *f2 = fopen(file_dst, "wb");

    if (!f1 || !f2)
        code = ERR_NO_FILE;
    else
        code = check_str(f1);

    if (code == OK)
    {
        int n = count_elems(f1);
        code = ERR_NO_ELEMENTS;

        for (int i = 0; i < n; i++)
        {
            student st; 
            get_student(f1, i, &st);
            
            char *surname = st.surname;

            if (strstr(surname, substr) == surname)
            {
                fwrite(&st, sizeof(student), 1, f2);
                code = OK;
            }
        }
    }

    fclose(f1);
    fclose(f2);

    return code;
}