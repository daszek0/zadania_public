// Jakub Daszkiewicz
// zadanie KULAWY SKOCZEK

#include <cstdio>
#include <algorithm>

using namespace std;

int r[1001][1001], dp[1001][1001];

int main()
{
	int n, x, y;
	scanf("%d", &n);
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < n; y++)
		{
			scanf("%d", &r[x][y]);
			dp[x][y] = -1;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < (n << 1); i++)
	{
		x = i;
		y = 0;
		while (x >= 0)
		{
			if (x < n && y < n && dp[x][y] >= 0)
			{
				dp[x][y] += r[x][y];
				if (x - 1 >= 0 && y + 2 < n)
				{
					dp[x - 1][y + 2] = max(dp[x][y], dp[x - 1][y + 2]);
				}
				if (x + 1 < n && y + 2 < n)
				{
					dp[x + 1][y + 2] = max(dp[x][y], dp[x + 1][y + 2]);
				}
				if (x + 2 < n && y + 1 < n)
				{
					dp[x + 2][y + 1] = max(dp[x][y], dp[x + 2][y + 1]);
				}
				if (x + 2 < n && y - 1 >= 0)
				{
					dp[x + 2][y - 1] = max(dp[x][y], dp[x + 2][y - 1]);
				}
			}
			x--;
			y++;
		}
	}
	printf("%d", dp[n - 1][n - 1]);
	return 0;
}