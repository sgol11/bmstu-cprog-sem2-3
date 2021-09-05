#include <stdio.h>
#include <string.h>

#define MAX_NUM_OF_WORDS 128
#define MAX_STLEN 256
#define MAX_WLEN 16

#define SEP_NUM 8

#define OK 0
#define BUFFER_OVERFLOW 1
#define LONG_WORD 2
#define EMPTY_STR 3
#define EMPTY_RES_STR 4

typedef struct
{
    char *str_words[MAX_NUM_OF_WORDS];
    size_t num_of_words;
} words_array;

int read_line(char *str, int n);
int split_into_words(char *str, words_array *words);
int fill_new_str(words_array *words, char *new_str);
void change_word(char *str);
void delete(char *str, int idx);
void print_error(int code);