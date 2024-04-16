// Jakub Daszkiewicz
// zadanie Teokracja

#include <cstdio>
#include <algorithm>

using namespace std;

long long qpowm(long long a, long long n, long long mod)
{
	if (n == 0)
        return 1;
    if (n == 1)
        return a;
    if (n % 2)
        return (a * qpowm(a, n - 1, mod)) % mod;
    long long m = qpowm(a, n >> 1, mod) % mod;
    return (m * m) % mod;
}

int main()
{
	long long a, b, c, d, p, ans;
	scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &p);
	while (c % p == 0)
	{
		c /= p;
		if (a % p == 0)
		{
			a /= p;
		}
		else if (b % p == 0)
		{
			b /= p;
		}
	}
	while (d % p == 0)
	{
		d /= p;
		if (a % p == 0)
		{
			a /= p;
		}
		else if (b % p == 0)
		{
			b /= p;
		}
	}
	a %= p;
	b %= p;
	ans = a * b;
	ans %= p;
	c %= p;
	ans *= qpowm(c, p - 2, p);
	ans %= p;
	d %= p;
	ans *= qpowm(d, p - 2, p);
	ans %= p;
	printf("%lld", ans);
	return 0;
}