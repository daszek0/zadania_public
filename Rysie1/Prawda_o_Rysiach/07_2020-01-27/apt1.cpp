// Jakub Daszkiewicz
// zadanie Apteka

#include <stdio.h>

using namespace std;

int main()
{
    unsigned n;
    scanf("%u", &n);
    unsigned long c[n];
    for (int i=0; i<n; i++)
    {
        scanf("%lu", &c[i]);
    }
    unsigned t = c[n-1];
    unsigned long long r = 0;
    for (int i=n-1; i>=0; i--)
    {
        if (c[i] < t) t = c[i];
        r += t;
    }
    printf("%llu", r);
    return 0;
}