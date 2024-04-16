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
		v.reset();
		a = 0;
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d %d", &t.y, &t.x, &t.r);
			s.push_back(t);
		}
		for (unsigned i = 0; i < s.size(); i++)
		{
			if (s[i].x - s[i].r <= 0)
			{
				bf.push_back(i);
			}
		}
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
	return 0;
}