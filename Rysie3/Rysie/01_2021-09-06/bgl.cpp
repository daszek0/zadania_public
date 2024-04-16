// Jakub Daszkiewicz
// zadanie Bieg uliczny

#include <cstdio>
#include <vector>

using namespace std;

vector<int> g[1000001];

int ans[1000001], sf[1000001], p[1000001];

void dfs(int n, int pr)
{
	for (auto i : g[n])
	{
		if (i != pr)
		{
			dfs(i, n);
			ans[n] += ans[i];
			p[n] += p[i];
		}
	}
	// a[n] += p[n] >> 1;
	p[n] += sf[n];
	if (p[n] >= 2)
	{
		ans[n]++;
		p[n] = 0;
	}
	// else if (p[n] == 1)
	// {
	// 	p[n] = 1;
	// }
	else if (p[n] == 0)
	{
		p[n] = 0;
	}
}

int main()
{
	int n, a, b, m;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a);
		sf[a] = 1;
	}
	dfs(1, 0);
	printf("%d", ans[1]);
	return 0;
}