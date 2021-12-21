#include "check_main.h"

typedef int(__cdecl *fn_fill_array_from_file_t)(char *, int *, int);

START_TEST(test_fill_arr_file_does_not_exist)
{
    HMODULE hlib;
    fn_fill_array_from_file_t fill_array_from_file;
    hlib = LoadLibrary("dyn2.dll");
    fill_array_from_file = (fn_fill_array_from_file_t)GetProcAddress(hlib, "fill_array_from_file");

    int arr[10] = { 0 };
    int n = 10;

    int rc = fill_array_from_file("unit_tests/files/does_not_exist.txt", arr, n);
    ck_assert_int_eq(rc, ERR_NO_FILE);

    FreeLibrary(hlib);
}
END_TEST

START_TEST(test_fill_arr_less_elements)
{
    HMODULE hlib;
    fn_fill_array_from_file_t fill_array_from_file;
    hlib = LoadLibrary("dyn2.dll");
    fill_array_from_file = (fn_fill_array_from_file_t)GetProcAddress(hlib, "fill_array_from_file");

    int arr[10] = { 0 };
    int n = 10;

    int rc = fill_array_from_file("unit_tests/files/fill_array_1.txt", arr, n);
    ck_assert_int_eq(rc, ERR_INPUT);

    FreeLibrary(hlib);
}
END_TEST

START_TEST(test_fill_arr_usual_ten_numbers)
{
    HMODULE hlib;
    fn_fill_array_from_file_t fill_array_from_file;
    hlib = LoadLibrary("dyn2.dll");
    fill_array_from_file = (fn_fill_array_from_file_t)GetProcAddress(hlib, "fill_array_from_file");

    int arr[10] = { 0 };
    int n = 10;

    int rc = fill_array_from_file("unit_tests/files/fill_array_2.txt", arr, n);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(*arr, -5);
    ck_assert_int_eq(*(arr + 9), 4);

    FreeLibrary(hlib);
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

    suite_add_tcase(s, tc_pos);

    return s;
}