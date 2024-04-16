#include <stdio.h>

using namespace std;

const unsigned long long mod=1000000007;

int main()
{
    unsigned long long n, a, r;
    scanf("%llu", &n);
    a = n+1;
    if (n%2 == 0) n /= 2;
    else a /= 2;
    a %= mod;
    n %= mod;
    printf("%llu", (a*n)%mod);
    return 0;
}
