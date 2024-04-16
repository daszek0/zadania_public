// Jakub Daszkiewicz
// zadanie Najdłuższa ścieżka

#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

vector<int> g[2001];
deque<int> lpnn; // liczby sąsiadów na najdłuższej ścieżce
int dn, dnd;
bool f;

void flps(int n, int p, int d)
{
	if (d > dnd)
	{
		dnd = d;
		dn = n;
	}
	for (auto i : g[n])
	{
		if (i != p)
		{
			flps(i, n, d + 1);
		}
	}
}

void flp(int n, int p, int t)
{
	lpnn.push_back(g[n].size());
	if (n == t)
	{
		f = true;
	}
	for (auto i : g[n])
	{
		if (f)
			break;
		if (i != p)
			flp(i, n, t);
	}
	if (!f)
	{
		lpnn.pop_back();
	}
}

int main()
{
	int n, k, a, b;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	flps(1, 0, 0);
	int s = dn;
	dnd = 0;
	flps(s, 0, 0);
	flp(s, 0, dn);
	a = 0;
	while ((int)lpnn.size() - 1 > k)
	{
		if (lpnn[1] < lpnn[lpnn.size() - 2])
		{
			lpnn.pop_front();
			a += lpnn.front() - 1;
			lpnn.front() = 1;
		}
		else
		{
			lpnn.pop_back();
			a += lpnn.back() - 1;
			lpnn.back() = 1;
		}
	}
	printf("%d", a);
	return 0;
}