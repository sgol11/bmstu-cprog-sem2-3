#include "check_main.h"
#include "check_one_element.h"
#include "check_whole_list.h"
#include "check_sort_list.h"

int main(void)
{
    int no_failed = 0;
    Suite *s1, *s2, *s3;
    SRunner *runner1, *runner2, *runner3;

    s1 = check_one_element();
    s2 = check_whole_list();
    s3 = check_sort_list();
    
    runner1 = srunner_create(s1);
    runner2 = srunner_create(s2);
    runner3 = srunner_create(s3);

    srunner_run_all(runner1, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner1);

    srunner_run_all(runner2, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner2);

    srunner_run_all(runner3, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner3);

    srunner_free(runner1);
    srunner_free(runner2);
    srunner_free(runner3);

    return (no_failed == 0) ? OK : FAIL;
}