// Jakub Daszkiewicz
// zadanie Podciągi zmienne

#include <cstdio>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;

int main()
{
	int n;
	scanf("%d", &n);
	long long dp[n], t;
	long long ost[500001];
	fill(ost, ost + 500001, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &t);
		if (i == 0)
		{
			ost[t] = 1;
			continue;
		}
		dp[i] = ((dp[i - 1] << 1) - ost[t] + 1 + mod) % mod;
		ost[t] = (dp[i - 1] + 1) % mod;
	}
	printf("%lld", dp[n - 1]);
	return 0;
}