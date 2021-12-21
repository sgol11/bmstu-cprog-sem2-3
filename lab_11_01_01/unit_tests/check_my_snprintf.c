#include "../inc/check_my_snprintf.h"

START_TEST(ch_char)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%c", 'a');
    int len2 = snprintf(res2, BUF_SIZE, "%c", 'a');

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%s", "hello world");
    int len2 = snprintf(res2, BUF_SIZE, "%s", "hello world");

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_str_null)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    char *str = NULL;
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%s", str);
    int len2 = snprintf(res2, BUF_SIZE, "%s", str);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_dec_max)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%d", INT_MAX);
    int len2 = snprintf(res2, BUF_SIZE, "%d", INT_MAX);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_dec_min)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%d", INT_MIN);
    int len2 = snprintf(res2, BUF_SIZE, "%d", INT_MIN);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_dec_positive)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%d", 156);
    int len2 = snprintf(res2, BUF_SIZE, "%d", 156);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_dec_negative)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%d", -156);
    int len2 = snprintf(res2, BUF_SIZE, "%d", -156);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_dec_null)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%d", 0);
    int len2 = snprintf(res2, BUF_SIZE, "%d", 0);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_hex_positive)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%x", 156);
    int len2 = snprintf(res2, BUF_SIZE, "%x", 156);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_hex_negative)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%x", -156);
    int len2 = snprintf(res2, BUF_SIZE, "%x", -156);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_hex_null)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%x", 0);
    int len2 = snprintf(res2, BUF_SIZE, "%x", 0);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_combo_1)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%s %c", "hello", '!');
    int len2 = snprintf(res2, BUF_SIZE, "%s %c", "hello", '!');

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_combo_2)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "{%s} {%d}", "hello", 123);
    int len2 = snprintf(res2, BUF_SIZE, "{%s} {%d}", "hello", 123);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_combo_3)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "test_%d: %s%c", 1, "success", '!');
    int len2 = snprintf(res2, BUF_SIZE, "test_%d: %s%c", 1, "success", '!');

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_dec_before_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%d hello", 2);
    int len2 = snprintf(res2, BUF_SIZE, "%d hello", 2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_dec_after_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "hello %d", 2);
    int len2 = snprintf(res2, BUF_SIZE, "hello %d", 2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_dec_between_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "hello %d world", 2);
    int len2 = snprintf(res2, BUF_SIZE, "hello %d world", 2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_max_dec_before_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%d hello", INT_MAX);
    int len2 = snprintf(res2, BUF_SIZE, "%d hello", INT_MAX);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_max_dec_after_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "hello %d", INT_MAX);
    int len2 = snprintf(res2, BUF_SIZE, "hello %d", INT_MAX);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_max_dec_between_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "hello %d world", INT_MAX);
    int len2 = snprintf(res2, BUF_SIZE, "hello %d world", INT_MAX);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_min_dec_before_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "%d hello", INT_MIN);
    int len2 = snprintf(res2, BUF_SIZE, "%d hello", INT_MIN);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_min_dec_after_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "hello %d", INT_MIN);
    int len2 = snprintf(res2, BUF_SIZE, "hello %d", INT_MIN);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_min_dec_between_str)
{
    char res1[BUF_SIZE], res2[BUF_SIZE];
    
    int len1 = my_snprintf(res1, BUF_SIZE, "hello %d world", INT_MIN);
    int len2 = snprintf(res2, BUF_SIZE, "hello %d world", INT_MIN);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(ch_null_buffer)
{
    int len1 = my_snprintf(NULL, 0, "%c%s%c", '!', "    ", '!');
    int len2 = snprintf(NULL, 0, "%c%s%c", '!', "    ", '!');

    ck_assert_int_eq(len1, len2);
}
END_TEST

Suite* check_my_snprintf(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("ch_my_snprintf");

    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, ch_char);
    tcase_add_test(tc_pos, ch_str);
    tcase_add_test(tc_pos, ch_str_null);
    tcase_add_test(tc_pos, ch_dec_max);
    tcase_add_test(tc_pos, ch_dec_min);
    tcase_add_test(tc_pos, ch_dec_positive);
    tcase_add_test(tc_pos, ch_dec_negative);
    tcase_add_test(tc_pos, ch_dec_null);
    tcase_add_test(tc_pos, ch_hex_positive);
    tcase_add_test(tc_pos, ch_hex_negative);
    tcase_add_test(tc_pos, ch_hex_null);
    tcase_add_test(tc_pos, ch_combo_1);
    tcase_add_test(tc_pos, ch_combo_2);
    tcase_add_test(tc_pos, ch_combo_3);
    tcase_add_test(tc_pos, ch_dec_before_str);
    tcase_add_test(tc_pos, ch_dec_after_str);
    tcase_add_test(tc_pos, ch_dec_between_str);
    tcase_add_test(tc_pos, ch_max_dec_before_str);
    tcase_add_test(tc_pos, ch_max_dec_after_str);
    tcase_add_test(tc_pos, ch_max_dec_between_str);
    tcase_add_test(tc_pos, ch_min_dec_before_str);
    tcase_add_test(tc_pos, ch_min_dec_after_str);
    tcase_add_test(tc_pos, ch_min_dec_between_str);
    tcase_add_test(tc_pos, ch_null_buffer);

    suite_add_tcase(s, tc_pos);

    return s;
}