#include "check_main.h"

START_TEST(test_filter_null_pb_src)
{
    int init_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int *res_pb = NULL, *res_pe = NULL;

    int rc = key(NULL, init_arr, &res_pb, &res_pe);
    ck_assert_int_eq(rc, ERR_NO_DATA);
    
    free(res_pb);
}
END_TEST

START_TEST(test_filter_null_pe_src)
{
    int init_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int *res_pb = NULL, *res_pe = NULL;

    int rc = key(init_arr, NULL, &res_pb, &res_pe);
    ck_assert_int_eq(rc, ERR_NO_DATA);
    
    free(res_pb);
}
END_TEST

START_TEST(test_filter_pb_equals_pe)
{
    int init_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int *res_pb = NULL, *res_pe = NULL;

    int rc = key(init_arr, init_arr, &res_pb, &res_pe);
    ck_assert_int_eq(rc, ERR_NO_DATA);
    
    free(res_pb);
}
END_TEST

START_TEST(test_filter_no_res_data)
{
    int n = 10;
    int init_arr[10] = { -5, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int *res_pb = NULL, *res_pe = NULL;

    int rc = key(init_arr, init_arr + n, &res_pb, &res_pe);
    ck_assert_int_eq(rc, ERR_NO_RES_DATA);
    
    free(res_pb);
}
END_TEST

START_TEST(test_filter_one_neg)
{
    int n = 10;
    int init_arr[10] = { 0, 1, 2, 3, 4, -5, 6, 7, 8, 9 };
    int *res_pb = NULL, *res_pe = NULL;

    int rc = key(init_arr, init_arr + n, &res_pb, &res_pe);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(res_pe - res_pb, 5);
    ck_assert_int_eq(*res_pb, 0);
    ck_assert_int_eq(*(res_pb + 4), 4);
    
    free(res_pb);
}
END_TEST

Suite* check_filter(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("filter");

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_filter_null_pb_src);
    tcase_add_test(tc_neg, test_filter_null_pe_src);
    tcase_add_test(tc_neg, test_filter_pb_equals_pe);
    tcase_add_test(tc_neg, test_filter_no_res_data);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_filter_one_neg);

    suite_add_tcase(s, tc_pos);

    return s;
}