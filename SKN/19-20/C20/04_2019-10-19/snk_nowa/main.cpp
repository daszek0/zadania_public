#include <stdio.h>

using namespace std;

int main()
{
    unsigned long long n, a, r;
    scanf("%llu", &n);
    if (n%2 == 0)
    {
        a = (n%1000000007+1)%1000000007;
        r = (a*(n/2))%1000000007;
    }
    else
    {
        a = n+1;
        r = (a*(n/2)+a/2)%1000000007;
    }
    printf("%llu", r);
    return 0;
}
