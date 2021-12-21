#include "check_one_element.h"
#include "check_sort_list.h"

node_t *create_not_sorted_list(int n)
{
    node_t *head = NULL;
    node_t *cur_node = head;

    for (int i = n; i > 0; i--)
    {
        node_t *new_node = NULL;

        new_node = create_int_node(i);

        if (head == NULL)
        {
            head = new_node;
            cur_node = new_node;
        }
        else
        {
            cur_node->next = new_node;
            cur_node = new_node;
        }
    }

    return head;
}

START_TEST(just_normal_sort)
{
    node_t *head = create_not_sorted_list(10);

    node_t *sorted_head = sort(head, comparator_int);

    ck_assert_int_eq(*(int*)(sorted_head->data), 1);

    free_int_list(&sorted_head);
}
END_TEST

Suite* check_sort_list(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("ch_sort");
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, just_normal_sort);

    suite_add_tcase(s, tc_pos);

    return s;
}