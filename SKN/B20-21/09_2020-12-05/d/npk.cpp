// Jakub Daszkiewicz
// zadanie Żetony

#include <stdio.h>

const long long mod = 1000000007;

long long fact_mod(long long n)
{
    long long r = 1;
    for (long long i = 2; i <= n; i++)
    {
        r *= i;
        r %= mod;
    }
    return r;
}

long long qpow_mod(long long a, long long n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    if (n % 2)
        return (a * qpow_mod(a, n - 1)) % mod;
    long long m = qpow_mod(a, n >> 1) % mod;
    return (m * m) % mod;
}

int main()
{
    long long g, r, b;
    scanf("%lld %lld %lld", &g, &r, &b);
    long long f = fact_mod(r + g + b);
    long long d = qpow_mod((((fact_mod(r) * fact_mod(g)) % mod) * fact_mod(b)) % mod, mod - 2);
    printf("%lld", (f * d) % mod);
    return 0;
}