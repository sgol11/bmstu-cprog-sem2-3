#include "unique_words.h"

int main(void)
{
    setbuf(stdout, NULL);

    int ret_code = OK;

    char str1[MAX_STLEN + 1], str2[MAX_STLEN + 1];
    words_array str1_words, str2_words;

    ret_code = read_line(str1, MAX_STLEN);
    ret_code = read_line(str2, MAX_STLEN);

    if (ret_code == OK)
    {
        split_into_words(str1, &str1_words, MAX_WLEN, &ret_code);
        split_into_words(str2, &str2_words, MAX_WLEN, &ret_code);

        if (ret_code == OK)
            unique_words(&str1_words, &str2_words, &ret_code);
    }

    print_error(ret_code);

    return ret_code;
}

int read_line(char *str, int n)
{
    int code = OK;
    int ch, i = 0;
    printf("Input line:\n");

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
        case NO_UNIQUE_WORDS:
            printf("Error: no unique words in the strings");
            break;
        case EMPTY_STR:
            printf("Error: no words in string(-s)");
            break;
        default:
            break;
    }
}
