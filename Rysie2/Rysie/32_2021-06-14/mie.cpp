// Jakub Daszkiewicz
// zadanie Miejsce zerowe

#include <cstdio>
#include <algorithm>

using namespace std;

double a, b, c, d;

double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
    double start, finish, check, v;
    scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &start, &finish);
    if (finish < start)
    {
        swap(start, finish);
    }
    if (f(start) > f(finish))
    {
        swap(start, finish);
    }
    while (true)
    {
        check = (start + finish) / 2;
        v = f(check);
        if (abs(v) <= 0.001)
        {
            printf("%lf", check);
            break;
        }
        else if (v < 0)
        {
            start = check;
        }
        else if (v > 0)
        {
            finish = check;
        }
    }
    return 0;
}
