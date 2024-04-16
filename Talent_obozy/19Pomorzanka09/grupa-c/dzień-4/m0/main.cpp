#include <bits/stdc++.h>
/*#include <iostream>
#include <stdio.h>
#include <math.h>*/

using namespace std;

double rf(double a)
{
    int c = a*10000;
    return c;
}

int main()
{
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double p, k, check, r;
    cin>>p>>k;
    // scanf("%lf, %lf", &p, &k);
    if (p > k)
        swap(p, k);

    while(true)
    {
        check = p+((k-p)/2);
        r = (a*check*check*check) + (b*check*check) + (c*check) + d;
        if (rf(r) >= -1 && rf(r) <= 1)
        {
            printf("%lf", check);
            break;
        }
        else if (r > 0)
        {
            k = check;
        }
        else if (r < 0)
        {
            p = check;
        }
    }

    return 0;
}
