// Jakub Daszkiewicz
// zadanie Obrazy

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
	int o, f, t, v;
	bool operator<(const edge &e) const
	{
		return o < e.o;
	}
};

const int O = 10001;
const int TS = 1 << 16;
int tr[TS];

void add(int f, int t, int v)
{
	while (f < t)
	{
		if (f & 1)
		{
			tr[f] += v;
			f >>= 1;
			f++;
		}
		else
		{
			f >>= 1;
		}
		if (t & 1)
		{
			t >>= 1;
		}
		else
		{
			tr[t] += v;
			t >>= 1;
			t--;
		}
	}
	if (f == t)
	{
		tr[f] += v;
	}
}

int read(int n)
{
	int r = 0;
	while (n)
	{
		r += tr[n];
		n >>= 1;
	}
	return r;
}

int main()
{
	int n, l, r, t, b;
	scanf("%d", &n);
	vector<edge> v, h;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &l, &b, &r, &t);
		l += O;
		b += O;
		r += O;
		t += O;
		h.push_back({l, b, t, 1});
		h.push_back({r, b, t, -1});
		v.push_back({b, l, r, 1});
		v.push_back({t, l, r, -1});
	}
	sort(h.begin(), h.end());
	sort(v.begin(), v.end());
	int ah = 0, av = 0;
	for (edge c : h)
	{
		add(c.f, c.t - 1, c.v);
		if (c.v == 1)
		{
			for (int i = c.f; i < c.t; i++)
			{
				if (read(i) == 1)
				{
					ah++;
				}
			}
		}
	}
	fill(tr, tr + TS, 0);
	for (edge c : v)
	{
		add(c.f, c.t - 1, c.v);
		if (c.v == 1)
		{
			for (int i = c.f; i < c.t; i++)
			{
				if (read(i) == 1)
				{
					av++;
				}
			}
		}
	}
	printf("%d", (ah + av) << 1);
	return 0;
}