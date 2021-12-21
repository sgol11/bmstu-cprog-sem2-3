#include "../inc/check_delete.h"

START_TEST(test_delete_rows)
{
    matrix_t matr;
    matr.rows = 5;
    matr.columns = 3;

    matr.data = allocate_matrix(matr.rows, matr.columns);
    if (matr.data)
    {
        for (int i = 0; i < matr.rows; i++)
            for (int j = 0; j < matr.columns; j++)
                matr.data[i][j] = i + j;
        
        square_matrix_by_removing(&matr);

        ck_assert_int_eq(matr.data[0][0], 0);
        ck_assert_int_eq(matr.data[1][0], 1);
        ck_assert_int_eq(matr.data[2][0], 2);

        free_matrix(matr.data, matr.rows);
    }
}
END_TEST

START_TEST(test_delete_columns)
{
    matrix_t matr;
    matr.rows = 3;
    matr.columns = 5;

    matr.data = allocate_matrix(matr.rows, matr.columns);
    if (matr.data)
    {
        for (int i = 0; i < matr.rows; i++)
            for (int j = 0; j < matr.columns; j++)
                matr.data[i][j] = i + j;

        matr.data[0][1] = 9;

        square_matrix_by_removing(&matr);

        ck_assert_int_eq(matr.data[0][0], 0);
        ck_assert_int_eq(matr.data[0][1], 2);
        ck_assert_int_eq(matr.data[0][2], 3);

        free_matrix(matr.data, matr.rows);
    }
}
END_TEST

Suite* check_delete(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("delete");
    
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_delete_rows);
    tcase_add_test(tc_pos, test_delete_columns);

    suite_add_tcase(s, tc_pos);

    return s;
}