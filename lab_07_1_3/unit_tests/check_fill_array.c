#include "check_fill_array.h"

START_TEST(test_fill_arr_file_does_not_exist)
{
    int arr[10] = { 0 };
    int n = 10;

    int rc = fill_array("unit_tests/files/does_not_exist.txt", arr, n);
    ck_assert_int_eq(rc, ERR_NO_FILE);
}
END_TEST

START_TEST(test_fill_arr_less_elements)
{
    int arr[10] = { 0 };
    int n = 10;

    int rc = fill_array("unit_tests/files/fill_array_1.txt", arr, n);
    ck_assert_int_eq(rc, ERR_INPUT);
}
END_TEST

START_TEST(test_fill_arr_usual_ten_numbers)
{
    int arr[10] = { 0 };
    int n = 10;

    int rc = fill_array("unit_tests/files/fill_array_2.txt", arr, n);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(*arr, -5);
    ck_assert_int_eq(*(arr + 9), 4);
}
END_TEST

START_TEST(test_fill_array_free)
{
    int n = 10;
    int *arr = NULL;
    arr = malloc(n * sizeof(int));
    int *p = arr;
    for (int i = 0; i < n; i++)
        *p++ = i;

    free_init_arr(&arr);
    ck_assert_ptr_null(arr);
}
END_TEST

Suite* check_fill_arr(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("fill_arr");

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_fill_arr_file_does_not_exist);
    tcase_add_test(tc_neg, test_fill_arr_less_elements);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_fill_arr_usual_ten_numbers);
    tcase_add_test(tc_pos, test_fill_array_free);

    suite_add_tcase(s, tc_pos);

    return s;
}