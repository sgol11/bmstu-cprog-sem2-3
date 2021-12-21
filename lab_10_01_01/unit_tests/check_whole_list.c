#include "check_one_element.h"
#include "check_whole_list.h"

START_TEST(no_duplicates)
{
    node_t *head = create_int_list(10);

    remove_duplicates(&head, comparator_int);

    ck_assert_int_eq(*(int*)(head->data), 0);

    free_int_list(&head);
}
END_TEST

Suite* check_whole_list(void)
{
    Suite *s;
    TCase *tc_neg;

    s = suite_create("ch_whole_list");

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, no_duplicates);
    
    suite_add_tcase(s, tc_neg);

    return s;
}