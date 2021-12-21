#include "io.h"

int input_command(void)
{
    int command = ERR_COMMAND;

    char action[COMMAND_LEN];

    int check = scanf("%4s", action); 

    if (check == 1 && action[3] == '\0')
    {
        if (strncmp(action, "out", COMMAND_LEN) == 0)
            command = OUT;
        else if (strncmp(action, "mul", COMMAND_LEN) == 0)
            command = MUL;
        else if (strncmp(action, "sqr", COMMAND_LEN) == 0)
            command = SQR;
        else if (strncmp(action, "div", COMMAND_LEN) == 0)
            command = DIV;
    }

    return command;
}

int input_numbers(int command, int *num_1, int *num_2)
{
    int rc = OK;

    if (command == OUT || command == SQR)
    {
        if (scanf("%d", num_1) != 1)
            rc = ERR_NUMBER;
    }
    else if (command == MUL || command == DIV)
    {
        if (scanf("%d", num_1) != 1)
            rc = ERR_NUMBER;
        if (rc == OK && scanf("%d", num_2) != 1)
            rc = ERR_NUMBER;
    }

    return rc;
}

void print_polynomial_factoring(node_t *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("L\n");
}