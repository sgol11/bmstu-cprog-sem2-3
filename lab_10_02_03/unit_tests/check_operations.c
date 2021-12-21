#include "../inc/check_operations.h"

START_TEST(ch_factoring)
{
    node_t *head = NULL;
    int num = 24;

    polynomial_factoring(num, &head);

    ck_assert_int_eq(head->data, 3);
    ck_assert_int_eq(head->next->data, 1);

    free_list(&head);
}
END_TEST

START_TEST(ch_multiplication)
{
    node_t *head_1 = NULL, *head_2 = NULL, *head_res = NULL;
    int num_1 = 24, num_2 = 5;

    polynomial_factoring(num_1, &head_1);
    polynomial_factoring(num_2, &head_2);
        
    multiplication(head_1, head_2, &head_res);
    
    ck_assert_int_eq(head_res->data, 3);
    ck_assert_int_eq(head_res->next->data, 1);
    ck_assert_int_eq(head_res->next->next->data, 1);

    free_list(&head_1);
    free_list(&head_2);
    free_list(&head_res);
}
END_TEST

START_TEST(ch_squaring)
{
    node_t *head = NULL, *head_res = NULL;
    int num = 27;

    polynomial_factoring(num, &head);

    squaring(head, &head_res);

    ck_assert_int_eq(head_res->data, 0);
    ck_assert_int_eq(head_res->next->data, 6);

    free_list(&head);
    free_list(&head_res);
}
END_TEST

START_TEST(ch_division)
{
    node_t *head_1 = NULL, *head_2 = NULL, *head_res = NULL;
    int num_1 = 24, num_2 = 5;

    polynomial_factoring(num_1, &head_1);
    polynomial_factoring(num_2, &head_2);
        
    division(head_1, head_2, &head_res);
        
    ck_assert_int_eq(head_res->data, 2);

    free_list(&head_1);
    free_list(&head_2);
    free_list(&head_res);
}
END_TEST

Suite* check_operations(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("ch_operations");

    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, ch_factoring);
    tcase_add_test(tc_pos, ch_multiplication);
    tcase_add_test(tc_pos, ch_squaring);
    tcase_add_test(tc_pos, ch_division);

    suite_add_tcase(s, tc_pos);

    return s;
}