#include "check_one_element.h"

node_t *create_int_node(int num)
{
    node_t *node = NULL;
    int *tmp_num = malloc(sizeof(int));
    *tmp_num = num;

    node = malloc(sizeof(node_t));

    node->data = (void*)tmp_num;
    node->next = NULL;

    return node;
}

node_t *create_int_list(int n)
{
    node_t *head = NULL;
    node_t *cur_node = head;

    for (int i = 0; i < n; i++)
    {
        node_t *new_node = create_int_node(i);

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

START_TEST(find_no_element)
{
    int element = 25;
    node_t *head = create_int_list(20);

    node_t *found_elem = find(head, &element, comparator_int);

    ck_assert_ptr_eq(found_elem, NULL);

    free_int_list(&head);
}
END_TEST

START_TEST(find_first)
{
    int element = 0;
    node_t *head = create_int_list(20);

    node_t *found_elem = find(head, &element, comparator_int);

    ck_assert_int_eq(*(int*)(found_elem->data), element);

    free_int_list(&head);
}
END_TEST

START_TEST(find_middle)
{
    int element = 10;
    node_t *head = create_int_list(20);

    node_t *found_elem = find(head, &element, comparator_int);

    ck_assert_int_eq(*(int*)(found_elem->data), element);

    free_int_list(&head);
}
END_TEST

START_TEST(find_last)
{
    int element = 19;
    node_t *head = create_int_list(20);

    node_t *found_elem = find(head, &element, comparator_int);

    ck_assert_int_eq(*(int*)(found_elem->data), element);

    free_int_list(&head);
}
END_TEST

START_TEST(pop_front_empty_list)
{
    node_t *head = NULL;
    int *pop_elem = pop_front(&head);

    ck_assert_ptr_eq(pop_elem, NULL);
}
END_TEST

START_TEST(pop_front_one_element_in_list)
{
    node_t *head = create_int_list(1);
    int *pop_elem = pop_front(&head);

    ck_assert_int_eq(*pop_elem, 0);
    ck_assert_ptr_eq(head, NULL);
    
    free(pop_elem);
    free_int_list(&head);
}
END_TEST


START_TEST(pop_front_normal)
{
    node_t *head = create_int_list(5);
    int *pop_elem = pop_front(&head);

    ck_assert_int_eq(*pop_elem, 0);
    
    free(pop_elem);
    free_int_list(&head);
}
END_TEST


START_TEST(pop_back_empty_list)
{
    node_t *head = NULL;
    int *pop_elem = pop_back(&head);

    ck_assert_ptr_eq(pop_elem, NULL);
}
END_TEST


START_TEST(pop_back_one_element_in_list)
{
    node_t *head = create_int_list(1);
    int *pop_elem = pop_back(&head);

    ck_assert_int_eq(*pop_elem, 0);
    ck_assert_ptr_eq(head, NULL);
    
    free(pop_elem);
    free_int_list(&head);
}
END_TEST

START_TEST(pop_back_normal)
{
    node_t *head = create_int_list(5);
    int *pop_elem = pop_back(&head);

    ck_assert_int_eq(*pop_elem, 4);
    
    free(pop_elem);
    free_int_list(&head);
}
END_TEST

START_TEST(insert_empty_list)
{
    int element = 10;

    node_t *head = NULL;

    node_t *insert_elem = create_int_node(element);

    insert(&head, insert_elem, NULL);

    ck_assert_int_eq(*(int*)(head->data), 10);

    free_int_list(&head);
}
END_TEST

START_TEST(insert_to_middle)
{
    int element = 10;

    node_t *head = create_int_list(10);

    node_t *insert_elem = create_int_node(element);

    insert(&head, insert_elem, head->next->next);

    ck_assert_int_eq(*(int*)(head->next->next->data), 10);

    free_int_list(&head);
}
END_TEST

Suite* check_one_element(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("ch_one_element");
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, find_first);
    tcase_add_test(tc_pos, find_middle);
    tcase_add_test(tc_pos, find_last);
    tcase_add_test(tc_pos, pop_front_one_element_in_list);
    tcase_add_test(tc_pos, pop_front_normal);
    tcase_add_test(tc_pos, pop_back_one_element_in_list);
    tcase_add_test(tc_pos, pop_back_normal);
    tcase_add_test(tc_pos, insert_empty_list);
    tcase_add_test(tc_pos, insert_to_middle);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, find_no_element);
    tcase_add_test(tc_neg, pop_front_empty_list);
    tcase_add_test(tc_neg, pop_back_empty_list);
    
    suite_add_tcase(s, tc_neg);

    return s;
}