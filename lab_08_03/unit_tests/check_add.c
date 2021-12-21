#include "../inc/check_add.h"

START_TEST(test_add_to_second_matrix)
{
    matrix_t A, B;
    A.rows = 5;
    A.columns = 5;
    B.rows = 2;
    B.columns = 2;

    A.data = allocate_matrix(A.rows, A.columns);
    B.data = allocate_matrix(B.rows, B.columns);

    if (A.data && B.data)
    {
        for (int i = 0; i < A.rows; i++)
            for (int j = 0; j < A.columns; j++)
                A.data[i][j] = i + j;

        B.data[0][0] = 5;
        B.data[0][1] = 3;
        B.data[1][0] = 4;
        B.data[1][1] = 2;

        one_size_by_adding(&A, &B);

        for (int i = 1; i < B.rows; i++)
            for (int j = 0; j < B.columns; j++)
            {
                if (j == 1)
                    ck_assert_int_eq(B.data[i][j], 2);
                else
                    ck_assert_int_eq(B.data[i][j], 4);
            }
        
        for (int j = 2; j < B.columns; j++)
            ck_assert_int_eq(B.data[0][j], 5);
    }

    free_matrix(A.data, A.rows);
    free_matrix(B.data, B.rows);
}
END_TEST

START_TEST(test_add_to_first_matrix)
{
    matrix_t A, B;
    A.rows = 2;
    A.columns = 2;
    B.rows = 5;
    B.columns = 5;

    A.data = allocate_matrix(A.rows, A.columns);
    B.data = allocate_matrix(B.rows, B.columns);

    if (A.data && B.data)
    {
        for (int i = 0; i < B.rows; i++)
            for (int j = 0; j < B.columns; j++)
                B.data[i][j] = i + j;

        A.data[0][0] = 5;
        A.data[0][1] = 3;
        A.data[1][0] = 4;
        A.data[1][1] = 2;

        one_size_by_adding(&A, &B);

        for (int i = 1; i < A.rows; i++)
            for (int j = 0; j < A.columns; j++)
            {
                if (j == 1)
                    ck_assert_int_eq(A.data[i][j], 2);
                else
                    ck_assert_int_eq(A.data[i][j], 4);
            }
        
        for (int j = 2; j < A.columns; j++)
            ck_assert_int_eq(A.data[0][j], 5);
    }

    free_matrix(A.data, A.rows);
    free_matrix(B.data, B.rows);
}
END_TEST

Suite* check_add(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("add");
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_add_to_first_matrix);
    tcase_add_test(tc_pos, test_add_to_second_matrix);

    suite_add_tcase(s, tc_pos);

    return s;
}