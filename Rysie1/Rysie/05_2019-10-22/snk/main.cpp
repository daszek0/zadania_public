#include <stdio.h>

using namespace std;

const unsigned long long mod = 1000000007;

unsigned long long n, np1;

int main()
{
    scanf("%llu", &n);
    np1 = n+1;
    if (n%2 == 0)
        n /= 2;
    else
        np1 /= 2;
    np1 %= mod;
    n %= mod;
    printf("%llu", n*np1%mod);
return 0;
}
