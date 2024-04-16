// Jakub Daszkiewicz
// zadanie Prawie równoważne słowa

#include <cstdio>

using namespace std;

const int N = 1000001;
const int P = 31;
const long long M = 694202137;

long long qpowm(long long a, long long n)
{
	if (a == 1 || n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return a % M;
	}
	if (n % 2)
	{
		return (a * qpowm(a, n - 1)) % M;
	}
	long long r = qpowm(a, n >> 1) % M;
	return (r * r) % M;
}

int main()
{
	int n;
	scanf("%d", &n);
	char w[N], p[N];
	scanf("%s %s", w, p);
	long long h = 0;
	for (int i = 0; i < n; i++)
	{
		h += (long long)(w[i] - 'a' + 1) * qpowm(P, n - 1 - i);
		h %= M;
	}
	for (int i = 0; i < n; i++)
	{
		// sprawdzenie
		// do dupy to wszystko
		h += M;
		h -= (long long)(w[i] - 'a' + 1) * qpowm(P, n - 1);
		h %= M;
		h *= P;
		h %= M;
		h += (long long)(w[i] - 'a' + 1);
		h %= M;
		// h = qpowm(h, P - 2); // ciekawe czy to w ogóle działa
		// h += (long long)(w[i] - 'a' + 1) * qpowm(P, n - 1);
		// h %= M;
	}
	return 0;
}