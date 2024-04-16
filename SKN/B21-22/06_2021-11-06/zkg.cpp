// Jakub Daszkiewicz
// zadanie Zakupowa gorączka

#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	long long p[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &p[i]);
	}
	sort(p, p + n, greater<int>());
	long long a = 0;
	for (int i = 0; i < n - 2; i++)
	{
		if (p[i] + p[i + 1] < (p[i] + p[i + 1] + p[i + 2]) * (100 - q) / 100)
		{
			a += p[i] + p[i + 1];
			p[i] = 0, p[i + 1] = 0, p[i + 2] = 0;
			i += 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		a += p[i] * (100 - q) / 100;
	}
	printf("%lld", a);
	return 0;
}