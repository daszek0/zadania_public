// Jakub Daszkiewicz
// zadanie Spokojna komisja

#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

vector<int> g[32001], gr[32001];
int v[32001];
stack<int> ks;

void kosaraju1(int n)
{
	v[n] = 1;
	for (auto i : g[n])
	{
		if (!v[i])
			kosaraju1(i);
	}
	ks.push(n);
}

void kosaraju2(int n, int c)
{
	v[n] = c;
	for (auto i : gr[n])
	{
		if (!v[i])
			kosaraju2(i, c);
	}
}

int main()
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		g[(i << 2) + 1].push_back((i << 2) + 4); // 1 więc nie 2
		g[(i << 2) + 2].push_back((i << 2) + 3); // nie 1 więc 2
		g[(i << 2) + 3].push_back((i << 2) + 2); // 2 więc nie 1
		g[(i << 2) + 4].push_back((i << 2) + 1); // nie 2 więc 1
		gr[(i << 2) + 1].push_back((i << 2) + 4);
		gr[(i << 2) + 2].push_back((i << 2) + 3);
		gr[(i << 2) + 3].push_back((i << 2) + 2);
		gr[(i << 2) + 4].push_back((i << 2) + 1);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		g[(a << 1) - 1].push_back((b << 1));
		gr[(b << 1)].push_back((a << 1) - 1);
		g[(b << 1) - 1].push_back((a << 1));
		gr[(a << 1)].push_back((b << 1) - 1);
	}
	for (int i = 1; i <= n << 2; i++)
	{
		if (!v[i])
		{
			kosaraju1(i);
		}
	}
	fill(v, v + 32001, 0);
	int c = 1;
	while (ks.size())
	{
		if (!v[ks.top()])
		{
			kosaraju2(ks.top(), c);
			c++;
		}
		ks.pop();
	}
	int ans[(n << 1) + 1];
	for (int i = 1; i <= n << 2; i += 2)
	{
		if (v[i] == v[i + 1])
		{
			printf("NIE");
			return 0;
		}
		ans[(i >> 1) + 1] = v[i] > v[i + 1];
	}
	for (int i = 1; i <= n << 1; i++)
	{
		if (ans[i])
		{
			printf("%d\n", i);
		}
	}
	return 0;
}