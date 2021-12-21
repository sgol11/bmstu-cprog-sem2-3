#include "check_main.h"

START_TEST(fill_no_numbers)
{
    int arr[10] = { 0 };
    fill_arr_with_prime_numbers(arr, 0);
    
    ck_assert_int_eq(arr[0], 0);
}
END_TEST

START_TEST(fill_one_number)
{
    int arr[10] = { 0 };
    fill_arr_with_prime_numbers(arr, 1);
    
    ck_assert_int_eq(arr[0], 2);
}
END_TEST

START_TEST(fill_ten_numbers)
{
    int arr[10] = { 0 };
    fill_arr_with_prime_numbers(arr, 10);
    
    ck_assert_int_eq(arr[0], 2);
    ck_assert_int_eq(arr[1], 3);
    ck_assert_int_eq(arr[2], 5);
    ck_assert_int_eq(arr[3], 7);
    ck_assert_int_eq(arr[4], 11);
    ck_assert_int_eq(arr[5], 13);
    ck_assert_int_eq(arr[6], 17);
    ck_assert_int_eq(arr[7], 19);
    ck_assert_int_eq(arr[8], 23);
    ck_assert_int_eq(arr[9], 29);
}
END_TEST

START_TEST(transfer_no_even)
{
    int arr_1[5] = { 1, 1, 1, 1, 1 }, arr_2[10] = { 0 };
    int n_res = arr_transfer(arr_1, arr_2, 5, -1);
    
    ck_assert_int_eq(arr_2[0], 1);
    ck_assert_int_eq(arr_2[1], 1);
    ck_assert_int_eq(arr_2[4], 1);

    ck_assert_int_eq(n_res, 5);
}
END_TEST

START_TEST(transfer_some_even)
{
    int arr_1[5] = { 1, 2, 3, 4, 5 }, arr_2[10] = { 0 };
    int n_res = arr_transfer(arr_1, arr_2, 5, -1);
    
    ck_assert_int_eq(arr_2[0], 1);
    ck_assert_int_eq(arr_2[1], 2);
    ck_assert_int_eq(arr_2[2], -1);
    ck_assert_int_eq(arr_2[3], 3);
    ck_assert_int_eq(arr_2[4], 4);
    ck_assert_int_eq(arr_2[5], -1);
    ck_assert_int_eq(arr_2[6], 5);

    ck_assert_int_eq(n_res, 7);
}
END_TEST

START_TEST(transfer_all_even)
{
    int arr_1[5] = { 2, 2, 2, 2, 2 }, arr_2[10] = { 0 };
    int n_res = arr_transfer(arr_1, arr_2, 5, -1);
    
    ck_assert_int_eq(arr_2[0], 2);
    ck_assert_int_eq(arr_2[1], -1);
    ck_assert_int_eq(arr_2[2], 2);
    ck_assert_int_eq(arr_2[3], -1);
    ck_assert_int_eq(arr_2[8], 2);
    ck_assert_int_eq(arr_2[9], -1);

    ck_assert_int_eq(n_res, 10);
}
END_TEST

START_TEST(transfer_second_arr_null)
{
    int arr_1[5] = { 2 };
    int n_res = arr_transfer(arr_1, NULL, 5, -1);

    ck_assert_int_eq(n_res, 10);
}
END_TEST

Suite* check_array_lib(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("array_lib");

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, transfer_second_arr_null);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, fill_no_numbers);
    tcase_add_test(tc_pos, fill_one_number);
    tcase_add_test(tc_pos, fill_ten_numbers);
    tcase_add_test(tc_pos, transfer_no_even);
    tcase_add_test(tc_pos, transfer_some_even);
    tcase_add_test(tc_pos, transfer_all_even);

    suite_add_tcase(s, tc_pos);

    return s;
}