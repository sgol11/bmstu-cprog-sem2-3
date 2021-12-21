#include "../inc/check_io.h"

START_TEST(io_file_does_not_exist)
{
    int n = 0;
    product_t *arr = NULL;

    int rc = read_file("unit_tests/files/does_not_exist.txt", &n, &arr);

    ck_assert_int_eq(rc, ERR_NO_FILE);
}
END_TEST

START_TEST(io_negative_products_num)
{
    int n = 0;
    product_t *arr = NULL;

    int rc = read_file("unit_tests/files/neg_num.txt", &n, &arr);

    ck_assert_int_eq(rc, ERR_PROD_NUM);
}
END_TEST

START_TEST(io_products_num_more_than_product_infos)
{
    int n = 0;
    product_t *arr = NULL;

    int rc = read_file("unit_tests/files/too_big_num.txt", &n, &arr);
    free_structs_arr(&arr, n);

    ck_assert_int_eq(rc, ERR_PROD_NUM);
}
END_TEST

START_TEST(io_negative_price)
{
    int n = 0;
    product_t *arr = NULL;

    int rc = read_file("unit_tests/files/neg_price.txt", &n, &arr);
    free_structs_arr(&arr, n);

    ck_assert_int_eq(rc, ERR_PRICE);
}
END_TEST

START_TEST(io_normal_test)
{
    int n = 0;
    product_t *arr = NULL;

    int rc = read_file("unit_tests/files/normal.txt", &n, &arr);
    ck_assert_int_eq(arr->price, 10);
    ck_assert_int_eq((arr + n - 1)->price, 90);

    free_structs_arr(&arr, n);

    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite* check_io(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("io");

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, io_file_does_not_exist);
    tcase_add_test(tc_neg, io_negative_products_num);
    tcase_add_test(tc_neg, io_products_num_more_than_product_infos);
    tcase_add_test(tc_neg, io_negative_price);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, io_normal_test);

    suite_add_tcase(s, tc_pos);

    return s;
}