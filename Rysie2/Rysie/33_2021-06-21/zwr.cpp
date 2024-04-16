// Jakub Daszkiewicz
// zadanie Zwrotnice

#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

vector<pair<int, int>> g[100000];

int bfs(int f, int t)
{
	int d[100000], c;
	fill(d, d + 100000, __INT_MAX__);
	deque<int> q;
	d[f] = 0;
	q.push_front(f);
	while (!q.empty())
	{
		c = q.front();
		q.pop_front();
		for (pair<int, int> i : g[c])
		{
			if (i.first + d[c] < d[i.second])
			{
				d[i.second] = i.first + d[c];
				if (i.second == t)
					return d[t];
				if (i.first)
					q.push_back(i.second);
				else
					q.push_front(i.second);
			}
		}
	}
	return d[t];
}

int main()
{
	int n, f, t, t0, t1;
	scanf("%d %d %d", &n, &f, &t);
	f--;
	t--;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &t0, &t1);
		g[i].push_back(make_pair(0, t0 - 1));
		g[i].push_back(make_pair(1, t1 - 1));
	}
	int a = bfs(f, t);
	if (a == __INT_MAX__)
		printf("BRAK");
	else
		printf("%d", a);
	return 0;
}