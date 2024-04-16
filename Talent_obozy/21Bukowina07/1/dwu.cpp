// Jakub Daszkiewicz
// zadanie Dwuszereg

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, pr[100001], t;
bool tb[100001];
vector<pair<int, bool>> g[50001];
int c[50001], cc[2], a;

void dfs(int n, int c_c)
{
	c[n] = c_c;
	cc[c_c]++;
	for (auto i : g[n])
	{
		if (c[i.first] == -1)
			dfs(i.first, c_c ^ i.second);
	}
}

int main()
{
	scanf("%d", &n);
	fill(pr, pr + 100001, -1);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (pr[t] == -1)
		{
			pr[t] = i;
		}
		else
		{
			g[pr[t]].push_back(make_pair(i, 1));
			g[i].push_back(make_pair(pr[t], 1));
			pr[t] = -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (pr[t] == -1)
		{
			pr[t] = i;
			tb[t] = true;
		}
		else
		{
			g[pr[t]].push_back(make_pair(i, tb[t]));
			g[i].push_back(make_pair(pr[t], tb[t]));
			pr[t] = -1;
		}
	}
	fill(c, c + 50001, -1);
	for (int i = 0; i < n; i++)
	{
		cc[0] = 0;
		cc[1] = 0;
		if (c[i] == -1)
			dfs(i, 0);
		a += min(cc[0], cc[1]);
	}
	printf("%d", a);
	return 0;
}