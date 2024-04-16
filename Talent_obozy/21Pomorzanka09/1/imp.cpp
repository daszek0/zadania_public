// Jakub Daszkiewicz
// zadanie Drogi

#include <cstdio>
#include <vector>

using namespace std;

int n; // liczba miast
int m; // liczba dróg
int a, b; // wczytywanie
vector<int> g[100001]; // graf
vector<int> gr[100001]; // graf odwrócony
int c[100001]; // półspójna miasta
int lc = 1; // ostatnia półspójna

void ac(int n, vector<int> g[])
{
	c[n] = lc;
	for (auto i : g[n])
	{
		if (!c[i])
		{
			ac(i, g);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		gr[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		if (gr[i].size() == 0)
		{
			ac(i, g);
			lc++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (gr[i].size() < g[i].size() && !c[i])
		{
			ac(i, g);
			lc++;
		}
	}
	a = lc - 1;
	fill(c, c + 100001, 0);
	lc = 1;
	for (int i = 0; i < n; i++)
	{
		if (g[i].size() == 0)
		{
			ac(i, gr);
			lc++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (g[i].size() < gr[i].size() && !c[i])
		{
			ac(i, gr);
			lc++;
		}
	}
	printf("%d", max(a, lc - 1));
	return 0;
}