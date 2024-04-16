// Jakub Daszkiewicz
// zadanie Bieg

#include <cstdio>
#include <unordered_map>

using namespace std;

unordered_map<int, pair<int, int>> g;

void dfs(int n, int p)
{
	if (n == 0)
		return;
	printf("%d ", n);
	if (g[n].first == p)
	{
		dfs(g[n].second, n);
	}
	else if (g[n].second == p)
	{
		dfs(g[n].first, n);
	}
}

int main()
{
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		if (g.count(a))
		{
			g[a].second = b;
		}
		else
		{
			g[a].first = b;
		}
		if (g.count(b))
		{
			g[b].second = a;
		}
		else
		{
			g[b].first = a;
		}
	}
	dfs(1, 0);
	return 0;
}