// Jakub Daszkiewicz
// zadanie Grzybki
//
// test 1: 3 1 1 2 5 5 3 7 2 4 => 2

#include <stdio.h>

#define ULL unsigned long long

using namespace std;

ULL max_a(ULL a[], ULL n)
{
    ULL r = 0;
    for (ULL i=0; i<n; i++)
        if (a[i] > r) r = a[i];
    return r;
}
ULL sum_a(ULL a[], ULL n)
{
    ULL r = 0;
    for (ULL i=0; i<n; i++)
        r += a[i];
    return r;
}

int main()
{
    unsigned int n;
    scanf("%u", &n);
    ULL m[n], p[n], d[n];
    bool b[n];
    for (unsigned int i=0; i<n; i++)
        b[i] = true;
    for (unsigned int i=0; i<n; i++)
        scanf("%llu %llu %llu", &m[i], &p[i], &d[i]);
    ULL end = max_a(d, n), r = 0;
    ULL max = 0;
    for (ULL i=1; i<end; i++)
    {
        for (ULL j=0; j<n; j++)
        {
            if (i == d[j])
            {
                b[j] = 0;
                m[j] = 0;
            }
            if (b[j])
            {
                m[j] += p[j];
            }
        }
        if (sum_a(m, n) > max)
        {
            r = i;
            max = sum_a(m, n);
        }
    }
    if (r == 0) r = 1;
    printf("%llu\n", r);
    return 0;
}