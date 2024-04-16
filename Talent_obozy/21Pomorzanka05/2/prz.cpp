// Jakub Daszkiewicz
// zadanie Przedsięwzięcie

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int N = 100000;
vector<int> g[N], gr[N];
int td[N], tl[N], t[N];

int main()
{
	int n, k, a, tt;
	bool ea[N];
	vector<int> eav;
	queue<int> bfs, bfsr;
	scanf("%d", &n);
	fill(ea, ea + n, true);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &t[i], &k);
		if (k == 0)
		{
			bfs.push(i);
		}
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &a);
			a--;
			ea[a] = false;
			g[a].push_back(i);
			gr[i].push_back(a);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (ea[i])
		{
			eav.push_back(i);
			bfsr.push(i);
		}
	}
	while (!bfs.empty())
	{
		k = 0;
		for (auto i : gr[bfs.front()])
		{
			if (td[i] == 0)
			{
				k = -1;
				break;
			}
			k = max(k, td[i]);
		}
		if (k != -1)
		{
			td[bfs.front()] = t[bfs.front()] + k;
			for (auto i : g[bfs.front()])
			{
				bfs.push(i);
			}
		}
		bfs.pop();
	}
	a = 0;
	for (int i = 0; i < n; i++)
	{
		a = max(a, td[i]);
		if (td[i] == 0)
		{
			printf("CYKL\n");
			return 0;
		}
	}
	printf("%d\n", a);
	fill(tl, tl + n, 2147483647);
	for (auto i : eav)
	{
		tl[i] = a;
	}
	while (!bfsr.empty())
	{
		for (auto i : gr[bfsr.front()])
		{
			tl[i] = min(tl[i], tl[bfsr.front()] - t[bfsr.front()]);
			bfsr.push(i);
		}
		bfsr.pop();
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &a, &tt);
		a--;
		if (td[a] + tt > tl[a])
		{
			printf("TAK\n");
		}
		else
		{
			printf("NIE\n");
		}
	}
	return 0;
}