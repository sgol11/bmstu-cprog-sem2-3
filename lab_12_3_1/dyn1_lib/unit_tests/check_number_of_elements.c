#include "check_main.h"

START_TEST(test_elem_num_file_does_not_exist)
{
    int rc = number_of_elements_from_file("unit_tests/files/does_not_exist.txt");
    ck_assert_int_eq(rc, ERR_NO_FILE);
}
END_TEST

START_TEST(test_elem_num_empty_file)
{
    int rc = number_of_elements_from_file("unit_tests/files/number_of_elements_1.txt");
    ck_assert_int_eq(rc, ERR_NO_DATA);
}
END_TEST

START_TEST(test_elem_num_usual_five_numbers)
{
    int rc = number_of_elements_from_file("unit_tests/files/number_of_elements_2.txt");
    ck_assert_int_eq(rc, 5);
}
END_TEST

Suite* check_elem_num(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("elem_num");

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_elem_num_file_does_not_exist);
    tcase_add_test(tc_neg, test_elem_num_empty_file);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_elem_num_usual_five_numbers);

    suite_add_tcase(s, tc_pos);

    return s;
}