#include "../inc/check_main.h"
#include "../inc/check_actions.h"
#include "../inc/check_operations.h"

int main(void)
{
    int no_failed = 0;
    Suite *s1, *s2;
    SRunner *runner1, *runner2;

    s1 = check_actions();
    s2 = check_operations();
    
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