#include "main.h"
#include "constants.h"
#include "my_snprintf.h"

int main(void)
{
    setbuf(stdout, NULL);

    int error_code = OK;

    char res1[100] = "", res2[100] = "";
    
    int len1 = my_snprintf(res1, 100, "%c%s%c", '!', "    ", '!');
    int len2 = snprintf(res2, 100, "%c%s%c", '!', "    ", '!');

    printf("%d\n%d\n", len1, len2);
    printf("{%s}\n{%s}\n", res1, res2);

    return error_code;
}
