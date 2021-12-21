#include "my_functions.h"

int my_getline(char **lineptr, int *n, FILE *stream)
{
    if (!stream)
        return -1;

    int exit = 0;
    char buf[BUF_SIZE];
    size_t buf_size = 0;

    *lineptr = NULL;
    *n = 0;

    char *tmp = NULL;

    while (!exit && (tmp = fgets(buf, BUF_SIZE, stream)) != NULL)
    {
        buf_size = strlen(buf);
        
        *lineptr = (char*)realloc(*lineptr, (*n + buf_size + 1) * sizeof(char));

        if (!(*lineptr))
        {
            exit = 1;
            *n = 0;
        }
        else
        {
            memcpy(*lineptr + *n, buf, buf_size);
            *n += buf_size;

            (*lineptr)[(*n)] = '\0';

            if ((*lineptr)[(*n) - 1] == '\n')
                exit = 1;
        }
    }

    return *n;
}

int my_getnum(FILE *file, int *rc)
{
    int num = 0;

    if (!file)
        *rc = ERR_NO_FILE;
    else
    {
        char *line = NULL;
        int len = 0;

        int tmp = my_getline(&line, &len, file);

        if (tmp != -1 && tmp != 0)
            num = atoi(line);
        else
            *rc = ERR_MEMORY;
        
        free(line);
        line = NULL;
    }
    
    return num;
}