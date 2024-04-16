// Jakub Daszkiewicz
// zadanie Historia pewnej wyspy

#include <stdio.h>
#include <math.h>

int main()
{
    double a, x, y;
    scanf("%lf %lf %lf", &a, &x, &y);
    printf("%.3lf %.3lf", 1 - (x * y) / (a * x + a * y - x * y), sqrt((fabs(2 * (a * x * (a - y)) / (a * y - 2 * x * y + a * x) - a) / 2) * (fabs(2 * (a * x * (a - y)) / (a * y - 2 * x * y + a * x) - a) / 2) + 3 * a * a / 4));
    return 0;
}