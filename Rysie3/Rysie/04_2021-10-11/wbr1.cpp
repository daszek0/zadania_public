// Jakub Daszkiewicz
// zadanie Wyścig robotów

#include <cstdio>
#include <algorithm>

using namespace std;

int t[2][100002], dp[2][1000002];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t[0][i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t[1][i]);
	}
	for (int i = 1; i <= n; i++)
	{
		dp[0][i] = dp[0][i - 1];
		if (t[0][i] == 0)
		{
			dp[0][i]++;
		}
		dp[1][i] = dp[1][i - 1];
		if (t[1][i] == 0)
		{
			dp[1][i]++;
		}
		if (dp[0][i] > dp[1][i])
		{
			dp[0][i] = dp[1][i];
			if (t[0][i] == 0)
			{
				dp[0][i]++;
			}
		}
		else if (dp[1][i] > dp[0][i])
		{
			dp[1][i] = dp[0][i];
			if (t[1][i] == 0)
			{
				dp[1][i]++;
			}
		}
		// dp[0][i] = min(dp[0][i], dp[1][i]); // dodać jeśli minujemy

		// dp[1][i] = min(dp[0][i], dp[1][i]);
	}
	// for (int i = 1; i <= n; i++)
	// {
	// 	printf("%d ", dp[0][i]);
	// }
	// printf("\n");
	// for (int i = 1; i <= n; i++)
	// {
	// 	printf("%d ", dp[1][i]);
	// }
	printf("%d", min(dp[0][n], dp[1][n]));
	return 0;
}