// Jakub Daszkiewicz
// zadanie Sygnalizacja świetlna

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int s, f, n, m, a, b, c, d[10001];
vector<pair<int, int>> g[10001];
pair<int, int> l[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dq;

int main()
{
	scanf("%d %d %d %d", &s, &f, &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back(make_pair(c, b));
		g[b].push_back(make_pair(c, a));
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &l[i].first, &l[i].second);
	}
	fill(d, d + 10001, -1);
	// d[s] = 0;
	dq.push(make_pair(0, s));
	while (!dq.empty() && d[f] == -1)
	{
		d[dq.top().second] = dq.top().first;
		for (auto i : g[dq.top().second])
		{
			if (d[i.second] == -1)
			{
				c = dq.top().first;
				if (dq.top().first % (l[dq.top().second].first + l[dq.top().second].second) >= l[dq.top().second].first)
				{
					c += l[dq.top().second].first + l[dq.top().second].second - (dq.top().first % (l[dq.top().second].first + l[dq.top().second].second));
				}
				c += i.first;
				dq.push(make_pair(c, i.second));
			}
		}
		dq.pop();
	}
	printf("%d", d[f]);
	return 0;
}