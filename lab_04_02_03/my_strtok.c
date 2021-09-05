#include "unique_words.h"

void split_into_words(char *str, words_array *words, int word_len, int *ret_code)
{
    int word_idx = 0;
    char *pword = my_strtok(str, SEP);

    while (pword)
    {
        if (strlen(pword) > MAX_WLEN)
            *ret_code = LONG_WORD;
        else
            words->str_words[word_idx++] = pword;
        pword = my_strtok(NULL, SEP);
    }

    words->num_of_words = word_idx;
    if (!word_idx)
        *ret_code = EMPTY_STR;
}

char *my_strtok(char *str, const char *separators)
{
    static char *ptr;
    
    if (str) 
    {
        ptr = str;
        while (*ptr && strchr(separators, *ptr))
            *ptr++ = '\0';
    }
    
    if (! *ptr)
        str = NULL;
    else
    {
        str = ptr;
    
        while (*ptr && !strchr(separators, *ptr))
            ptr++;
        while (*ptr && strchr(separators, *ptr))
            *ptr++ = '\0';
    }
    
    return str;
}