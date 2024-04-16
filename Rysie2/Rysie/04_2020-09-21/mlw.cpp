// Jakub Daszkiewicz
// zadanie Malowanie

#include <stdio.h>

using namespace std;

const long long mod = 1000000007;

long long qpow2(long long n)
{
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (n % 2) return (qpow2(n - 1) << 1) % mod;
    long long ret2 = qpow2(n >> 1);
    return (ret2 * ret2) % mod;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    if (n == 1) printf("4");
    else printf("%lld", qpow2(n) * 3 % mod);
    return 0;
}