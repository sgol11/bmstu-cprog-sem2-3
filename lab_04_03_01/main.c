#include "string_conversion.h"

int main(void)
{
    setbuf(stdout, NULL);

    int ret_code = OK;

    char str[MAX_STLEN + 1], new_str[MAX_STLEN + 1];
    words_array str_words;

    new_str[0] = '\0';

    ret_code = read_line(str, MAX_STLEN);

    if (ret_code == OK)
    {
        ret_code = split_into_words(str, &str_words);

        if (ret_code == OK)
        {
            ret_code = fill_new_str(&str_words, new_str);

            if (ret_code == OK)
                printf("Result: %s\n", new_str);
        }
    }

    print_error(ret_code);

    return ret_code;
}

int read_line(char *str, int n)
{
    int code = OK;
    int ch, i = 0;
    printf("Input string:\n");

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i < n)
            str[i] = ch;
        i++;
    }
    
    if (i > n)
        code = BUFFER_OVERFLOW;
        
    i = (i <= n) ? i : n;
    str[i] = '\0';

    return code;
}

void print_error(int code)
{
    switch (code)
    {
        case BUFFER_OVERFLOW:
            printf("Error: buffer overflow");
            break;
        case LONG_WORD:
            printf("Error: some words are too long");
            break;
        case EMPTY_STR:
            printf("Error: no words in initial string");
            break;
        case EMPTY_RES_STR:
            printf("Error: no words in resulting string");
            break;
        default:
            break;
    }
}
