// Jakub Daszkiewicz
// zadanie Minimalne połączenia gazociągu

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
	int t, id, x, y, s, u;
	friend bool operator<(const point &p0, const point &p1)
	{
		if (p0.s == p1.s)
		{
			return p0.t < p1.t;
		}
		return p0.s < p1.s;
	}
};

int main()
{
	int n, x, y;
	scanf("%d", &n);
	vector<point> p;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		p.push_back({0, i + 1, x, 100000 - y, x + 100000 - y, 0});
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		p.push_back({1, i + 1, x, 100000 - y, x + 100000 - y, 0});
	}
	sort(p.begin(), p.end());
	vector<pair<int, int>> a;
	long long as = 0;
	vector<point>::iterator c0 = p.begin(), c1 = p.begin();
	while (a.size() < n)
	{
		while (c0->t != 0)
		{
			c0++;
		}
		c1 = c0;
		while (c1->t != 1 || c1->y < c0->y || c1->x < c0->x || c1->u)
		{
			c1++;
		}
		as += c1->s - c0->s;
		a.push_back(make_pair(c0->id, c1->id));
		c1->u = 1;
		c0++;
	}
	printf("%lld\n", as);
	for (auto i : a)
	{
		printf("%d %d\n", i.first, i.second);
	}
	return 0;
}