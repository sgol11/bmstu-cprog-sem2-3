#include "io.h"

int read_file(char *file_name, node_t **head)
{
    int rc = OK;

    FILE *file = fopen(file_name, "r");

    if (!file)
        rc = ERR_NO_FILE;

    if (rc == OK)
    {
        rc = read_structs(file, head);
        fclose(file);
    }

    return rc;
}

int read_structs(FILE *f, node_t **head)
{
    int rc = OK;

    node_t *cur_node = *head;

    while (rc == OK && !feof(f) && !ferror(f))
    {
        char *tmp_name = NULL;
        int tmp_year = 0;
        
        rc = read_movie_info(f, &tmp_name, &tmp_year);

        if (rc == OK)
        {
            node_t *new_node = create_node(tmp_name, tmp_year);

            if (new_node && *head == NULL)
            {
                *head = new_node;
                cur_node = new_node;
            }
            else if (new_node)
            {
                cur_node->next = new_node;
                cur_node = new_node;
            }
            else
                rc = ERR_MEMORY;
        }
        
        free(tmp_name);
    }

    return rc;
}

int read_movie_info(FILE *f, char **tmp_name, int *tmp_year)
{
    int rc = OK; 

    *tmp_name = NULL;

    char *line = NULL;
    int len = 0;

    rc = my_getline(&line, &len, f);

    if (rc == OK)
    {
        *tmp_name = malloc((len + 1) * sizeof(char));

        if (!(*tmp_name))
            rc = ERR_MEMORY;
        else
            strcpy(*tmp_name, line);

        free(line);
        line = NULL;
    }
        
    if (len == 1)
        rc = ERR_EMPTY_STR;
        
    *tmp_year = my_getnum(f, &rc);
        
    if (*tmp_year <= 0)
        rc = *tmp_year;

    return rc;
}

node_t *create_node(char *name, int year)
{
    node_t *node = NULL;
    movie_t *movie = NULL;
    char *name_copy = NULL;

    node = malloc(sizeof(node_t));

    if (node)
    {
        movie = malloc(sizeof(movie_t));

        if (movie)
        {
            name_copy = strdup(name);

            if (name_copy)
            {
                movie->name = name_copy;
                movie->year = year;

                node->data = (void*)movie;
                node->next = NULL;
            }
            else
            {
                free(node);
                node = NULL;
                free(movie);
                movie = NULL;
            }
        }
        else
        {
            free(node);
            node = NULL;
        }
    }

    return node;
}

int write_list_into_file(char *file_name, node_t *head)
{
    int rc = OK;

    FILE *file = fopen(file_name, "w");

    if (!file)
        rc = ERR_NO_FILE;

    if (rc == OK)
    {
        node_t *cur_node = head;

        while (cur_node)
        {
            movie_t *cur_movie = cur_node->data;
            fprintf(file, "%s\n%d\n", cur_movie->name, cur_movie->year);
            cur_node = cur_node->next;
        }
        
        fclose(file);
    }

    return rc;
}