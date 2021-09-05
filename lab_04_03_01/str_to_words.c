#include "string_conversion.h"

int split_into_words(char *str, words_array *words)
{
    int code = OK;
    char *separators = "\n ,;:-.!?";
    int word_idx = 0;

    char *pword = strtok(str, separators);

    while (pword)
    {
        if (strlen(pword) > MAX_WLEN)
            code = LONG_WORD;
        else
            words->str_words[word_idx++] = pword;
        pword = strtok(NULL, separators);
    }

    words->num_of_words = word_idx;
    if (!word_idx)
        code = EMPTY_STR;

    return code;
}