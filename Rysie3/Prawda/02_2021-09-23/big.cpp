// Jakub Daszkiewicz
// zadanie Bieg

#include <cstdio>
#include <vector>

using namespace std;

vector<int> g[100001];

void dfs(int n, int p)
{
	printf("%d ", n);
	for (auto i : g[n])
	{
		if (i != p)
		{
			dfs(i, n);
		}
	}
}

int main()
{
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	return 0;
}