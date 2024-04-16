// Jakub Daszkiewicz
// zadanie Bardzo Żarłoczny Smok

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    long long a, b, c, r, t;
    scanf("%lld", &q);
    for (int p=0; p<q; p++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (__gcd(a, c) != 1)
        {
            printf("-1\n");
            continue;
        }
        r = 0;
        t = 0;
        while (t != b)
        {
            t += a;
            t %= c;
            r++;
        }
        printf("%lld\n", r);
    }
    return 0;
}