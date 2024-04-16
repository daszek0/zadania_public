// Jakub Daszkiewicz
// zadanie Doskonały słuch

#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct ss
{
	int x, y, r;
};

const int N = 3001;
int z, n, m, k, a;
// vector<int> g[N];
vector<ss> s;
bitset<N> v;

int dfs(int n)
{
	if (s[n].x + s[n].r >= m)
	{
		return 1;
	}
	int ret = 0;
	long long x, y, r;
	v[n] = 1;
	for (unsigned i = 0; i < s.size(); i++)
	{
		if (!v[i])
		{
			x = s[n].x - s[i].x;
			y = s[n].y - s[i].y;
			r = s[n].r + s[i].r;
			if (x * x + y * y <= r * r)
			{
				ret = dfs(i);
			}
		}
		if (ret)
		{
			return ret;
		}
	}
	// for (auto i : g[n])
	// {
	// 	if (!v[i])
	// 	{
	// 		r = dfs(i);
	// 	}
	// 	if (r)
	// 	{
	// 		break;
	// 	}
	// }
	return ret;
}

int main()
{
	ss t;
	vector<int> bf;
	scanf("%d", &z);
	for (int i = 0; i < z; i++)
	{
		scanf("%d %d %d", &n, &m, &k);
		s.clear();
		bf.clear();
		// ei.reset();
		v.reset();
		// for (int i = 0; i < N; i++)
		// {
		// 	g[i].clear();
		// 	g[i].shrink_to_fit();
		// }
		// a = -1;
		a = 0;
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d %d", &t.y, &t.x, &t.r);
			s.push_back(t);
		}
		for (unsigned i = 0; i < s.size(); i++)
		{
			// for (unsigned j = i + 1; j < s.size(); j++)
			// {
			// 	x = s[i].x - s[j].x;
			// 	y = s[i].y - s[j].y;
			// 	r = s[i].r + s[j].r;
			// 	if (x * x + y * y <= r * r) // odległość <= r1+r2
			// 	{
			// 		g[i].push_back(j);
			// 		g[j].push_back(i);
			// 	}
			// }
			// for (int i = 0; i < N; i++)
			// {
			// 	g[i].shrink_to_fit();
			// }
			if (s[i].x - s[i].r <= 0)
			{
				bf.push_back(i);
			}
			// if (s[i].x + s[i].r >= m)
			// {
			// 	ei[i] = 1;
			// 	a = 0;
			// }
		}
		// if (a == -1)
		// {
		// 	printf("TAK\n");
		// }
		// else
		// {
			for (auto i : bf)
			{
				if (a)
				{
					break;
				}
				a += dfs(i);
			}
			printf(a ? "NIE\n" : "TAK\n");
		// }
	}
	return 0;
}