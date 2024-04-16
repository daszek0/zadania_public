// Jakub Daszkiewicz
// zadanie Biegi uliczne

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> g[1000001];
int dp[1000001][2], s[1000001];

void dfs(int n, int p)
{
	vector<pair<int, int>> x;
	int s0 = 0;
	for (auto i : g[n])
	{
		if (i != p)
		{
			dfs(i, n);
			dp[n][0] += dp[i][0];
			dp[n][1] = max(dp[n][1], dp[i][1]);
			if (s[n])
			{
				dp[n][0] = max(dp[n][0], dp[i][1]);
			}
			x.push_back(make_pair(dp[i][1], dp[i][0]));
			s0 += dp[i][0];
		}
	}
	sort(x.begin(), x.end(), greater<pair<int, int>>());
	if (x.size() >= 2)
	{
		dp[n][0] = max(dp[n][0], s0 + x[0].first + x[1].first - x[0].second - x[1].second);
	}
	if (s[n])
	{
		dp[n][1] = max(dp[n][1], s0);
	}
}

int main()
{
	int n, a, b, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
		dp[i + 1][1] = -__INT_MAX__ - 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a);
		s[a] = 1;
		dp[a][1] = 0;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%d %d\n", dp[i][0], dp[i][1]);
	}
	// printf("%d", dp[1][0]);
	return 0;
}
