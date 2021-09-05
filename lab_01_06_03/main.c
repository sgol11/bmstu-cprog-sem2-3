/**
Назначение программы: определение местоположения
точки относительно прямой по заданным координатам
точек
 */

#include <stdio.h>
#include <math.h>

int dot_match(double x1, double y1, double x2, double y2);
int location(double x1, double y1, double x2, double y2,
double x3, double y3);
void print_error(int code);

int main(void)
{
    setbuf(stdout, NULL);
    double xq, yq, xr, yr, xp, yp;
    int q, r, p;
    int error_code = 0, res = -1;

    printf("Input coordinates: ");
    q = scanf("%lf%lf", &xq, &yq);
    r = scanf("%lf%lf", &xr, &yr);
    p = scanf("%lf%lf", &xp, &yp);

    if (q != 2 || r != 2 || p != 2)
        error_code = 1;
    else if (dot_match(xq, yq, xr, yr))
        error_code = 2;
    else
        res = location(xq, yq, xr, yr, xp, yp);

    if (error_code == 0)
        printf("Dot location = %d\n", res);
    else
        print_error(error_code);

    return error_code;
}

int dot_match(double x1, double y1, double x2, double y2)
{
    double eps = 1e-7;
    int flag = 0;

    if (fabs(x1 - x2) < eps && fabs(y1 - y2) < eps)
        flag = 1;

    return flag;
}

int location(double x1, double y1, double x2, double y2,
double x3, double y3)
{
    double vectors_multiply;
    int loc;

    // косое произведение векторов
    vectors_multiply = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (x1 > x2)
        vectors_multiply *= -1;

    if (vectors_multiply > 0.0)
        loc = 0; // выше прямой
    else if (vectors_multiply < 0.0)
        loc = 2; // под прямой
    else
        loc = 1; // на прямой

    return loc;
}

void print_error(int code)
{
    switch (code)
    {
        case 1:
            printf("Error: input error\n");
            break;
        case 2:
            printf("Error: dots match\n");
            break;
        default:
            break;
    }
}
