#include "../inc/check_sort.h"

START_TEST(test_mysort_null_arr)
{
    int n = 10;

    int rc = mysort(NULL, n, sizeof(int), compare_int);
    ck_assert_int_eq(rc, ERR_NO_DATA);
}
END_TEST

START_TEST(test_mysort_zero_elements_cnt)
{
    int init_arr[10] = { 9, -8, 7, -6, 5, -4, 3, -2, 1, 0 };

    int rc = mysort(init_arr, 0, sizeof(int), compare_int);
    ck_assert_int_eq(rc, ERR_NO_DATA);
}
END_TEST

START_TEST(test_mysort_usual_arr)
{
    int n = 10;
    int init_arr[10] = { 9, -8, 7, -6, 5, -4, 3, -2, 1, 0 };

    int rc = mysort(init_arr, n, sizeof(int), compare_int);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(*init_arr, -8);
    ck_assert_int_eq(*(init_arr + 1), -6);
    ck_assert_int_eq(*(init_arr + 2), -4);
    ck_assert_int_eq(*(init_arr + 7), 5);
    ck_assert_int_eq(*(init_arr + 8), 7);
    ck_assert_int_eq(*(init_arr + 9), 9);
}
END_TEST

Suite* check_mysort(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("ch_mysort");

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_mysort_null_arr);
    tcase_add_test(tc_neg, test_mysort_zero_elements_cnt);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_mysort_usual_arr);

    suite_add_tcase(s, tc_pos);

    return s;
}