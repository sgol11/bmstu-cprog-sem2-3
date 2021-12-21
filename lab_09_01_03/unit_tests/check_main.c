#include "../inc/check_main.h"
#include "../inc/check_io.h"
#include "../inc/check_choose.h"

int main(void)
{
    int no_failed = 0;
    Suite *s1, *s2;
    SRunner *runner1, *runner2;

    s1 = check_io();
    s2 = check_choose();
    
    runner1 = srunner_create(s1);
    runner2 = srunner_create(s2);

    srunner_run_all(runner1, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner1);

    srunner_run_all(runner2, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner2);

    srunner_free(runner1);
    srunner_free(runner2);

    return (no_failed == 0) ? OK : FAIL;
}