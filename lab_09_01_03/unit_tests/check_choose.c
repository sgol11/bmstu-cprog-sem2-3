#include "../inc/check_choose.h"

START_TEST(choose_no_suitable)
{
    int n = 0, new_n = 0;
    double p = 5.0;
    product_t *init = NULL, *res = NULL;

    int rc = read_file("unit_tests/files/normal.txt", &n, &init);
    
    new_n = choose_products(init, &res, n, p);
    ck_assert_int_eq(new_n, 0);

    free_structs_arr(&init, n);
    free_structs_arr(&res, new_n);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(choose_all_suitable)
{
    int n = 0, new_n = 0;
    double p = 100.0;
    product_t *init = NULL, *res = NULL;

    int rc = read_file("unit_tests/files/normal.txt", &n, &init);
    
    new_n = choose_products(init, &res, n, p);
    ck_assert_int_eq(new_n, 5);

    free_structs_arr(&init, n);
    free_structs_arr(&res, new_n);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(choose_some_suitable)
{
    int n = 0, new_n = 0;
    double p = 50;
    product_t *init = NULL, *res = NULL;

    int rc = read_file("unit_tests/files/normal.txt", &n, &init);
    
    new_n = choose_products(init, &res, n, p);
    ck_assert_int_eq(new_n, 2);

    free_structs_arr(&init, n);
    free_structs_arr(&res, new_n);

    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite* check_choose(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("ch_choose");
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, choose_no_suitable);
    tcase_add_test(tc_pos, choose_all_suitable);
    tcase_add_test(tc_pos, choose_some_suitable);

    suite_add_tcase(s, tc_pos);

    return s;
}