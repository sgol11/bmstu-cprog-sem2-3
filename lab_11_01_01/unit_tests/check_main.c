#include "../inc/check_main.h"
#include "../inc/check_my_snprintf.h"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = check_my_snprintf();
    
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? OK : FAIL;
}