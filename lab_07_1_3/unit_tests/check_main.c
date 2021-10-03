#include "../inc/check_main.h"
#include "../inc/check_filter.h"
#include "../inc/check_fill_array.h"
#include "../inc/check_number_of_elements.h"
#include "../inc/check_sort.h"
#include "../inc/check_output.h"

int main(void)
{
    int no_failed = 0;
    Suite *s1, *s2, *s3, *s4, *s5;
    SRunner *runner1, *runner2, *runner3, *runner4, *runner5;

    s1 = check_elem_num();
    s2 = check_fill_arr();
    s3 = check_filter();
    s4 = check_mysort();
    s5 = check_output();
    
    runner1 = srunner_create(s1);
    runner2 = srunner_create(s2);
    runner3 = srunner_create(s3);
    runner4 = srunner_create(s4);
    runner5 = srunner_create(s5);

    srunner_run_all(runner1, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner1);

    srunner_run_all(runner2, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner2);

    srunner_run_all(runner3, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner3);

    srunner_run_all(runner4, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner4);
    
    srunner_run_all(runner5, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner5);

    srunner_free(runner1);
    srunner_free(runner2);
    srunner_free(runner3);
    srunner_free(runner4);
    srunner_free(runner5);

    return (no_failed == 0) ? OK : FAIL;
}