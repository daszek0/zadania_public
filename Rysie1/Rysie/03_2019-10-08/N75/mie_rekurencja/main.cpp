#include <bits/stdc++.h>

using namespace std;

double a, b, c, d, start, finish, x, f;

double check(double s, double e)
{
    x = (s+e)/2;
    f = a*x*x*x+b*x*x+c*x+d;
    if (abs(f) <= 0.0001)
    {
        return x;
    }
    else if (f<0)
    {
        return check(x, e);
    }
    else
    {
        return check(s, x);
    }
}

int main()
{
    scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &start, &finish);
    if (finish < start)
    {
        double z = start;
        start = finish;
        finish = z;
    }
    printf("%.4lf", check(start, finish));
    return 0;
}
