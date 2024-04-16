// Jakub Daszkiewicz
// zadanie Zbieranie grzybów

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, l, p, ms;
	scanf("%d %d", &n, &k);
	scanf("%d %d", &l, &p);
	int m[n + 1][2];
	fill(&m[0][0], (&m[n][1]) + 1, 0);
	int dp[n + 1][k + 1];
	fill(&dp[0][0], (&dp[n][k]) + 1, 0);
	for (int i = 0; i < l; i++)
	{
		scanf("%d", &ms);
		m[ms][0] = 1;
	}
	for (int i = 0; i < p; i++)
	{
		scanf("%d", &ms);
		m[ms][1] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + m[i][0];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = max(dp[i - 1][j] + m[i][j & 1], dp[i - 1][j - 1] + m[i][j & 1] + m[i][(j & 1) ^ 1]);
		}
	}
	printf("%d", dp[n][k]);
	return 0;
}