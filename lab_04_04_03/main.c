#include "phone_number.h"

int main(void)
{
    setbuf(stdout, NULL);

    int ret_code = OK;
    int result = 0;

    char str[MAX_STLEN + 1];

    ret_code = read_line(str, MAX_STLEN);

    if (ret_code == OK)
    {
        result = processing_string(str);
        if (result)
            printf("YES");
        else
            printf("NO");
    }

    return ret_code;
}

int read_line(char *str, int n)
{
    int code = OK;
    char ch;
    int i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF && i < n)
    {
        str[i++] = ch;
    }

    str[i] = '\0';
    
    if (i == n && ch != '\n' && ch != EOF)
        code = BUFFER_OVERFLOW;

    return code;
}
