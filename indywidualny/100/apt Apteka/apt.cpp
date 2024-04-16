// Jakub Daszkiewicz
// zadanie Apteka

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, m = __INT_MAX__;
	long long a = 0;
	scanf("%d", &n);
	int c[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		m = min(m, c[i]);
		a += m;
	}
	printf("%lld", a);
	return 0;
}