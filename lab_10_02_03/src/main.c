#include "main.h"
#include "constants.h"
#include "io.h"
#include "actions.h"

int main(void)
{
    setbuf(stdout, NULL);

    int error_code = OK;
    
    int number_1, number_2;

    int command = input_command();

    if (command != ERR_COMMAND)
        error_code = input_numbers(command, &number_1, &number_2);
    else
        error_code = ERR_COMMAND;

    if (error_code == OK)
    {
        switch (command)
        {
            case OUT:
                error_code = do_out(number_1);
                break;
            case MUL:
                error_code = do_mul(number_1, number_2);
                break;
            case SQR:
                error_code = do_sqr(number_1);
                break;
            case DIV:
                error_code = do_div(number_1, number_2);
                break;
            default:
                break;
        }
    }

    return error_code;
}
