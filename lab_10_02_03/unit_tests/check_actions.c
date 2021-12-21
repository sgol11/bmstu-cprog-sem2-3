#include "../inc/check_actions.h"

START_TEST(out_normal)
{
    int num = 24;
    int rc = do_out(num);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(out_zero)
{
    int num = 0;
    int rc = do_out(num);
    ck_assert_int_eq(rc, ERR_ZERO_RES);
}
END_TEST

START_TEST(mul_normal)
{
    int num_1 = 24, num_2 = 3;
    int rc = do_mul(num_1, num_2);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(mul_zero)
{
    int num_1 = 0, num_2 = 3;
    int rc = do_mul(num_1, num_2);
    ck_assert_int_eq(rc, ERR_ZERO_RES);
}
END_TEST

START_TEST(sqr_normal)
{
    int num = 121;
    int rc = do_sqr(num);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(sqr_zero)
{
    int num = 0;
    int rc = do_sqr(num);
    ck_assert_int_eq(rc, ERR_ZERO_RES);
}
END_TEST

START_TEST(div_normal)
{
    int num_1 = 24, num_2 = 5;
    int rc = do_div(num_1, num_2);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(div_zero)
{
    int num_1 = 0, num_2 = 5;
    int rc = do_div(num_1, num_2);
    ck_assert_int_eq(rc, ERR_ZERO_RES);
}
END_TEST

Suite* check_actions(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("ch_actions");
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, out_normal);
    tcase_add_test(tc_pos, mul_normal);
    tcase_add_test(tc_pos, sqr_normal);
    tcase_add_test(tc_pos, div_normal);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, out_zero);
    tcase_add_test(tc_neg, mul_zero);
    tcase_add_test(tc_neg, sqr_zero);
    tcase_add_test(tc_neg, div_zero);

    suite_add_tcase(s, tc_neg);

    return s;
}