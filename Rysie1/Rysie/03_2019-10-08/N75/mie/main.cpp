#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, c, d, start, finish, check, v;
    scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &start, &finish);
    if (finish < start)
    {
        double z = start;
        start = finish;
        finish = z;
    }
    while (true)
    {
        check = (start+finish)/2;
        v = a*check*check*check+b*check*check+c*check+d;
        if (abs(v) <= 0.001)
        {
            printf("%lf", check);
            break;
        }
        else if (v<0)
        {
            start = check;
        }
        else
        {
            finish = check;
        }
    }
    return 0;
}
