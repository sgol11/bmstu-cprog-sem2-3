#include "../inc/check_multi.h"

START_TEST(test_multi_zero_powers)
{
    matrix_t A, B, C;
    A.rows = 3;
    A.columns = 3;
    B.rows = 3;
    B.columns = 3;
    int p = 0, q = 0;

    A.data = allocate_matrix(A.rows, A.columns);
    B.data = allocate_matrix(B.rows, B.columns);

    if (A.data && B.data)
    {
        for (int i = 0; i < A.rows; i++)
            for (int j = 0; j < A.columns; j++)
            {
                A.data[i][j] = i;
                B.data[i][j] = j;
            }

        calculate(&A, p, &B, q, &C);

        ck_assert_int_eq(C.data[0][0], 1);
        ck_assert_int_eq(C.data[1][1], 1);
        ck_assert_int_eq(C.data[2][2], 1);
    }

    free_matrix(A.data, A.rows);
    free_matrix(B.data, B.rows);
    free_matrix(C.data, C.rows);
}
END_TEST

START_TEST(test_multi_powers_one)
{
    matrix_t A, B, C;
    A.rows = 3;
    A.columns = 3;
    B.rows = 3;
    B.columns = 3;
    int p = 1, q = 1;

    A.data = allocate_matrix(A.rows, A.columns);
    B.data = allocate_matrix(B.rows, B.columns);

    if (A.data && B.data)
    {
        for (int i = 0; i < A.rows; i++)
            for (int j = 0; j < A.columns; j++)
            {
                A.data[i][j] = i;
                B.data[i][j] = j;
            }

        calculate(&A, p, &B, q, &C);

        ck_assert_int_eq(C.data[0][0], 0);
        ck_assert_int_eq(C.data[1][1], 3);
        ck_assert_int_eq(C.data[2][2], 12);
    }

    free_matrix(A.data, A.rows);
    free_matrix(B.data, B.rows);
    free_matrix(C.data, C.rows);
}
END_TEST

Suite* check_multi(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("multi");
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_multi_zero_powers);
    tcase_add_test(tc_pos, test_multi_powers_one);

    suite_add_tcase(s, tc_pos);

    return s;
}