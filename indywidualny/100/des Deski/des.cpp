// Jakub Daszkiewicz
// zadanie Deski

#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int l[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &l[i]);
	}
	sort(l, l + n, greater<int>());
	if (n > 3)
	{
		printf("%lld", (long long)l[3] * (long long)l[3]);
	}
	else
	{
		printf("0");
	}
	return 0;
}