// Jakub Daszkiewicz
// zadanie Drzewo rzędu K

#include <cstdio>
#include <deque>

using namespace std;

int n, k;

struct nn
{
	deque<short> p; // liczba na pozycji
	bool operator!=(const nn &a) const
	{
		return p != a.p;
	}
	bool operator>(const nn &a) const
	{
		return p.size() > a.p.size();
	}
	nn operator+(int x)
	{
		nn r = *this;
		r.p[0] += x;
		for (int i = 0; i < r.p.size(); i++)
		{
			if (r.p[i] >= k)
			{
				if (i + 1 < r.p.size())
				{
					r.p[i + 1] += r.p[i] / k;
				}
				else
				{
					r.p.push_back(r.p[i] / k);
				}
				r.p[i] %= k;
			}
		}
		return r;
	}
	nn operator+=(int x)
	{
		*this = *this + x;
		return *this;
	}
	void up()
	{
		p.pop_front();
	}
	void zero()
	{
		p.clear();
		p.push_back(0);
	}
};

int main()
{
	int q, x, y, ans;
	nn a, b;
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &x, &y);
		a.zero();
		b.zero();
		ans = 0;
		a += x;
		b += y;
		if (b > a)
		{
			swap(a, b);
		}
		while (a > b)
		{
			a += k - 2;
			a.up();
			ans++;
		}
		while (a != b)
		{
			a += k - 2;
			a.up();
			b += k - 2;
			b.up();
			ans += 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}