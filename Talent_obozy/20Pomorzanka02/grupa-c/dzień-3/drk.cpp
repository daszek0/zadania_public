// Jakub Daszkiewicz
// zadanie Drzewo rzędu K

#include <stdio.h>
// #include <algorithm>

#define ull unsigned long long

using namespace std;

ull n;
unsigned k;

ull qpow(ull a, ull n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n % 2 == 0)
    {
        ull p = qpow(a, n/2);
        return p*p;
    }
    else return a*qpow(a, n-1);
}

ull find(ull from, ull to, ull r)
{
    if (from == to) return r;
    r++;
    if (from < to)
    {
        ull t = to;
        to = from;
        from = t;
    }
    if (from > to)
    {
        for (int i=2-k; i<=1; i++)
        {
            if ((from-i) % k == 0) return find((from-i)/k, to, r);
        }
    }
}

int main()
{
    unsigned q;
    ull x, y;
    scanf("%llu %u %u", &n, &k, &q);
    for (int p=0; p<q; p++)
    {
        scanf("%llu %llu", &x, &y);
        // if (y > x) swap(x, y);
        printf("%llu\n", find(x, y, 0));
    }
    return 0;
}