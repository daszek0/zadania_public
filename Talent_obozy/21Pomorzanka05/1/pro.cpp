// Jakub Daszkiewicz
// zadanie Profesor Szu

#include <cstdio>
#include <vector>

using namespace std;

const int N = 1000001;
vector<int> g[N], gr[N]; // iterujemy się po reversed
int v[N];
int d[N];

void dfs(int n)
{
	v[n] = 1;
	for (auto it : g[n])
	{
		d[n] += d[it];
		if (d[it] == 0)
		{
			d[n] = 0;
			v[n] = 0;
			return;
		}
	}
	for (auto it : gr[n])
	{
		if (!v[it])
		{
			dfs(it);
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		g[(a == n + 1) ? 0 : a].push_back((b == n + 1) ? 0 : b);
		gr[(b == n + 1) ? 0 : b].push_back((a == n + 1) ? 0 : a); // TAAAAK
	}
	d[0] = 1;
	dfs(0);
	for (int i = 1; i <= n; i++)
	{
		if (d[i] >= 36500)
		{
			d[i] = 0;
		}
	}
	int ad = 0, an = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			ad = 0;
			break;
		}
		ad = max(ad, d[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == ad)
		{
			an++;
		}
	}
	if (ad == 0)
	{
		printf("zawsze\n");
	}
	else
	{
		printf("%d\n", ad);
	}
	printf("%d\n", an);
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == ad)
		{
			printf("%d ", i);
		}
	}
	return 0;
}