/**
Назначение программы: поиск величины перемещения
по начальной скорости, ускорению и времени
 */

#include <stdio.h>

double distance(double v0, double a, double t);

int main(void)
{
    setbuf(stdout, NULL);
    double speed, acceleration, time;

    printf("Input initial speed, acceleration and time: ");
    scanf("%lf%lf%lf", &speed, &acceleration, &time);

    double res = distance(speed, acceleration, time);

    printf("Total distance = %.6lf\n", res);

    return 0;
}

double distance(double v0, double a, double t)
{
    return v0 * t + a * t * t / 2;
}
