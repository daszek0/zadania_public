// Jakub Daszkiewicz
// zadanie Kolorowa plansza

#include <cstdio>

using namespace std;

const long long mod = 1000000009;

long long fact(long long a)
{
	long long r = 1;
	for (long long i = 2; i <= a; i++)
	{
		r *= i;
		r %= mod;
	}
	return r;
}

long long qpowm(long long a, long long n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return a % mod;
	}
	if (n & 1)
	{
		long long r = qpowm(a, n - 1);
		r *= a;
		return r % mod;
	}
	long long r = qpowm(a, n >> 1);
	return (r * r) % mod;
}

int main()
{
	// n! ^ m
	long long n, m;
	scanf("%lld %lld", &n, &m);
	printf("%lld", qpowm(fact(n), m));
	return 0;
}