// Jakub Daszkiewicz
// zadanie Biegi uliczne

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> g[1000001], x;
int dp[1000001][2], s[1000001];

void dfs(int n, int p)
{
//	x.clear();
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
//			x.push_back(dp[i][1]);
		}
	}
//	sort(x.begin(), x.end(), greater<int>());
//	if (x.size() > 1)
//	{
//		dp[n][0] += x[0];
//		dp[n][0] += x[1];
//		dp[n][0]--;
//	}
	
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
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a);
		s[a] = 1;
		dp[a][1] = 1;
	}
	dfs(1, 0);
	printf("%d", dp[1][0]);
	return 0;
}
