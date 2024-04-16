// Jakub Daszkiewicz
// zadanie Drzewo rzędu K

#include <stdio.h>

#define ull unsigned long long

using namespace std;

ull n;
unsigned k;

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
    return find((from-1)/k, to, r);
}

int main()
{
    unsigned q;
    ull x, y;
    scanf("%llu %u %u", &n, &k, &q);
    for (int p=0; p<q; p++)
    {
        scanf("%llu %llu", &x, &y);
        printf("%llu\n", find(x-1, y-1, 0));
    }
    return 0;
}