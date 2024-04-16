// Jakub Daszkiewicz
// zadanie Doskonały słuch

#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct ss
{
	long long x, y, r;
};

const int N = 3001;
vector<int> g[N];
bitset<N> ei, v;

int dfs(int n)
{
	if (ei[n])
	{
		return 1;
	}
	int r = 0;
	v[n] = 1;
	for (auto i : g[n])
	{
		if (!v[i])
		{
			r = dfs(i);
		}
	}
	return r;
}

int main()
{
	int z, n, m, k, a;
	ss t;
	vector<ss> s;
	vector<int> bf;
	scanf("%d", &z);
	for (int i = 0; i < z; i++)
	{
		scanf("%d %d %d", &n, &m, &k);
		s.clear();
		bf.clear();
		ei.reset();
		v.reset();
		for (int i = 0; i < N; i++)
		{
			g[i].clear();
		}
		a = -1;
		for (int i = 0; i < k; i++)
		{
			scanf("%lld %lld %lld", &t.y, &t.x, &t.r);
			s.push_back(t);
		}
		for (unsigned i = 0; i < s.size(); i++)
		{
			for (unsigned j = i + 1; j < s.size(); j++)
			{
				if (abs(s[i].x - s[j].x) * abs(s[i].x - s[j].x) + abs(s[i].y - s[j].y) * abs(s[i].y - s[j].y) <= (s[i].r + s[j].r) * (s[i].r + s[j].r)) // odległość <= r1+r2
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
			if (s[i].x - s[i].r <= 0)
			{
				bf.push_back(i);
			}
			if (s[i].x + s[i].r >= m)
			{
				ei[i] = 1;
				a = 0;
			}
		}
		if (a == -1)
		{
			printf("TAK\n");
		}
		else
		{
			for (auto i : bf)
			{
				if (a)
				{
					break;
				}
				a += dfs(i);
			}
			printf(a ? "NIE\n" : "TAK\n");
		}
	}
	return 0;
}