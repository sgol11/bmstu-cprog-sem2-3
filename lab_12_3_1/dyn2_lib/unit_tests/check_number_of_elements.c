#include "check_main.h"

typedef int(__cdecl *fn_number_of_elements_from_file_t)(char *);

START_TEST(test_elem_num_file_does_not_exist)
{
    HMODULE hlib;
    fn_number_of_elements_from_file_t number_of_elements_from_file;
    hlib = LoadLibrary("dyn2.dll");
    number_of_elements_from_file = (fn_number_of_elements_from_file_t)GetProcAddress(hlib, "number_of_elements_from_file");

    int rc = number_of_elements_from_file("unit_tests/files/does_not_exist.txt");
    ck_assert_int_eq(rc, ERR_NO_FILE);

    FreeLibrary(hlib);
}
END_TEST

START_TEST(test_elem_num_empty_file)
{
    HMODULE hlib;
    fn_number_of_elements_from_file_t number_of_elements_from_file;
    hlib = LoadLibrary("dyn2.dll");
    number_of_elements_from_file = (fn_number_of_elements_from_file_t)GetProcAddress(hlib, "number_of_elements_from_file");

    int rc = number_of_elements_from_file("unit_tests/files/number_of_elements_1.txt");
    ck_assert_int_eq(rc, ERR_NO_DATA);

    FreeLibrary(hlib);
}
END_TEST

START_TEST(test_elem_num_usual_five_numbers)
{
    HMODULE hlib;
    fn_number_of_elements_from_file_t number_of_elements_from_file;
    hlib = LoadLibrary("dyn2.dll");
    number_of_elements_from_file = (fn_number_of_elements_from_file_t)GetProcAddress(hlib, "number_of_elements_from_file");

    int rc = number_of_elements_from_file("unit_tests/files/number_of_elements_2.txt");
    ck_assert_int_eq(rc, 5);

    FreeLibrary(hlib);
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