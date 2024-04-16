// Jakub Daszkiewicz
// zadanie Pożar

#include <cstdio>
#include <vector>

using namespace std;

int n, m, v[200000], a, b, q, vis[200000];
vector<int> g[200000];

long long dfs(int n)
{
	vis[n] = 1;
	long long s = v[n];
	for (int i : g[n])
	{
		if (!vis[i])
		{
			s += dfs(i);
		}
	}
	return s;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &a, &b);
		b--;
		if (a)
		{
			g[b].clear();
			v[b] = 0;
		}
		else
		{
			fill(vis, vis + 200000, 0);
			printf("%lld\n", dfs(b));
		}
	}
	return 0;
}