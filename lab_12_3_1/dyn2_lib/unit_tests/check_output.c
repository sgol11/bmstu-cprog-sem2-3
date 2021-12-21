#include "check_main.h"

typedef int(__cdecl *fn_write_into_file_t)(char *, int *, int *);

START_TEST(test_output_usual)
{
    HMODULE hlib;
    fn_write_into_file_t write_into_file;
    hlib = LoadLibrary("dyn2.dll");
    write_into_file = (fn_write_into_file_t)GetProcAddress(hlib, "write_into_file");

    int n = 10;
    int init_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int rc = write_into_file("unit_tests/files/check_out.txt", init_arr, init_arr + n);
    ck_assert_int_eq(rc, OK);

    FreeLibrary(hlib);
}
END_TEST

Suite* check_output(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("output");
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_output_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}