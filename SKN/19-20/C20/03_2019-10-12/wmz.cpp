#include <stdio.h>

using namespace std;

long long qpow(long long a, long long n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return a;
    else if (n%2 == 0)
        return qpow(a, n/2) * qpow(a, n/2);
    else
        return qpow(a, n-1) * a;
}

int main()
{
    int a;
    long long r = 0;
    scanf("%d", &a);
    for (int i=0; i<a; i++)
    {
        r = (r+qpow(4, i))%500000009;
    }
    printf("%lld", r);
    return 0;
}
