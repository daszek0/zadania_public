// Jakub Daszkiewicz
// zadanie Sklep akwarystyczny

#include <cstdio>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

const long long p = 10000000000000061;
long long s[1000001];
long long e[1000002];

int main()
{
	mt19937 mt(694202137);
	long long f[1000001];
	for (int i = 0; i <= 1000000; i++)
	{
		f[i] = uniform_int_distribution<long long>(1, p - 1)(mt);
	}
	int n, q, a, b, c;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		e[a] += f[c];
		e[a] %= p;
		e[b + 1] += p - f[c];
		e[b + 1] %= p;
	}
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + e[i];
		s[i] %= p;
	}
	unordered_set<long long> ss;
	ss.insert(s + 1, s + n + 1);
	printf("%u", ss.size());
	return 0;
}