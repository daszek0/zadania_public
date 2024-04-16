// Jakub Daszkiewicz
// zadanie Janosik

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int s = 2;
    long long a = 0;
    for (int i = 3; i <= n; i++)
    {
        if (__builtin_popcount(i) == 1) s = i;
        a += (long long)(i - s);
    }
    printf("%lld", a);
    return 0;
}