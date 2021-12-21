#include "my_functions.h"

int my_getline(char **lineptr, int *n, FILE *stream)
{
    int rc = OK;

    if (!stream)
        return ERR_NO_FILE;
    
    int exit = 0;
    char buf[BUF_SIZE];
    size_t buf_size = 0;

    *lineptr = NULL;
    *n = 0;

    char *tmp = NULL;

    while (rc == OK && !exit && (tmp = fgets(buf, BUF_SIZE, stream)) != NULL)
    {
        buf_size = strlen(buf);
        
        *lineptr = (char*)realloc(*lineptr, (*n + buf_size + 1) * sizeof(char));

        if (!(*lineptr))
            rc = ERR_MEMORY;
        else
        {
            memcpy(*lineptr + *n, buf, buf_size);
            *n += buf_size;

            (*lineptr)[(*n)] = '\0';

            if ((*lineptr)[(*n) - 1] == '\n')
            {
                (*lineptr)[(*n) - 1] = '\0';
                exit = 1;
            }
        }
    }

    if (*n == 0)
        rc = ERR_EMPTY_STR;

    return rc;
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

        *rc = my_getline(&line, &len, file);

        if (*rc == OK)
            num = atoi(line);
        
        free(line);
        line = NULL;
    }
    
    return num;
}