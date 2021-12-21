#include "check_main.h"

int main(void)
{
    int no_failed = 0;
    Suite *s1;
    SRunner *runner1;

    s1 = check_array_lib();
    
    runner1 = srunner_create(s1);

    srunner_run_all(runner1, CK_VERBOSE);

    srunner_free(runner1);

    return (no_failed == 0) ? OK : FAIL;
}