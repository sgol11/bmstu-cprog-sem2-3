/**
Назначение программы: нахождение площади треугольника
по двум сторонам и углу между ними
 */

#include <stdio.h>
#include <math.h>

#define PI (4.0 * atan(1.0))

double area(double x, double y, double alpha);

int main(void)
{
    setbuf(stdout, NULL);
    double a, b, fi;
    double s;

    printf("Input sides and angle in degrees: ");
    scanf("%lf%lf%lf", &a, &b, &fi);

    s = area(a, b, fi);

    printf("Triangle area = %.6lf\n", s);

    return 0;
}

double area(double x, double y, double alpha)
{
    return 0.5 * x * y * sin(alpha * (PI/180));
}
