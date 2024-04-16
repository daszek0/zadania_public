// Jakub Daszkiewicz
// zadanie Przeskocz szachownicę!

#include <cstdio>
#include <vector>

using namespace std;

struct bignum
{
	vector<char> d = {0};
	void write()
	{
		for (int i = d.size() - 1; i >= 0; i--)
		{
			putchar_unlocked(d[i] + '0');
		}
	}
	bignum operator+(bignum n)
	{
		bignum ret = *this;
		if (ret.d.size() < n.d.size())
			swap(ret.d, n.d);
		for (unsigned i = 0; i < n.d.size(); i++)
		{
			ret.d[i] += n.d[i];
		}
		for (unsigned i = 1; i < ret.d.size(); i++)
		{
			if (ret.d[i - 1] >= 10)
			{
				ret.d[i] += ret.d[i - 1] / 10;
				ret.d[i - 1] %= 10;
			}
		}
		char t;
		while (ret.d.back() >= 10)
		{
			t = ret.d.back();
			ret.d.back() = t % 10;
			ret.d.push_back(t / 10);
		}
		return ret;
	}
	void operator+=(const bignum n)
	{
		*this = *this + n;
	}
	bignum operator++()
	{
		d[0]++;
		for (unsigned i = 1; i < d.size(); i++)
		{
			if (d[i - 1] == 10)
			{
				d[i]++;
				d[i - 1] = 0;
			}
		}
		if (d.back() == 10)
		{
			d.back() = 0;
			d.push_back(1);
		}
		return *this;
	}
};

int n;
bignum w[101][101];

int main()
{
	scanf("%d", &n);
	int t;
	w[0][0].d = {1};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &t);
			if (t == 0)
			{
				continue;
			}
			if (i + t < n)
			{
				w[i + t][j] += w[i][j];
			}
			if (j + t < n)
			{
				w[i][j + t] += w[i][j];
			}
		}
	}
	// printf("%lld", w[n - 1][n - 1]);
	w[n - 1][n - 1].write();
	return 0;
}