// Jakub Daszkiewicz
// zadanie Bankomaty

#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

struct bignum
{
	vector<char> d;
	void read()
	{
		d.clear();
		char c = getchar_unlocked();
		while (c < '0' || c > '9')
			c = getchar_unlocked();
		while (c >= '0' && c <= '9')
		{
			d.push_back(c - '0');
			c = getchar_unlocked();
		}
		reverse(d.begin(), d.end());
	}
	int div2mod2()
	{
		bool mod = 0;
		for (int i = d.size() - 1; i >= 0; i--)
		{
			d[i] += mod * 10;
			mod = d[i] & 1;
			d[i] >>= 1;
			if (!d.empty() && d.back() == 0)
				i++;
			while (!d.empty() && d.back() == 0)
			{
				d.pop_back();
				i--;
			}
		}
		return mod;
	}
};

const int N = 100;

int main()
{
	int n;
	scanf("%d", &n);
	bitset<N> b;
	bignum t;
	vector<int> o;
	int lb;
	for (int i = 0; i < n; i++)
	{
		t.read();
		lb = 0;
		// b = t;
		while (!t.d.empty())
		{
			b[lb] = t.div2mod2();
			lb++;
		}
		// dodawanie
		o.clear();
		o.push_back(-1);
		for (int j = 0; j < N; j++)
		{
			if (b[j])
			{
				if (j & 1)
				{
					if (o.back() == j)
					{
						o.pop_back();
					}
					else
					{
						o.push_back(j);
						o.push_back(j + 1);
					}
				}
				else
				{
					if (o.back() == j)
					{
						o.pop_back();
						o.push_back(j + 1);
						o.push_back(j + 2);
					}
					else
					{
						o.push_back(j);
					}
				}
			}
		}
		sort(o.begin(), o.end(), greater<int>());
		if (o.back() > 99)
		{
			printf("NIE");
		}
		else
		{
			for (auto j : o)
			{
				if (j != -1)
					printf("%d ", j);
			}
		}
		printf("\n");
		// odejmowanie
		o.clear();
		o.push_back(-1);
		for (int j = 0; j < N; j++)
		{
			if (b[j])
			{
				if (j & 1)
				{
					if (o.back() == j)
					{
						o.pop_back();
						o.push_back(j + 2);
						o.push_back(j + 1);
					}
					else
					{
						o.push_back(j);
					}
				}
				else
				{
					if (o.back() == j)
					{
						o.pop_back();
					}
					else
					{
						o.push_back(j);
						o.push_back(j + 1);
					}
				}
			}
		}
		sort(o.begin(), o.end(), greater<int>());
		if (o.back() > 99)
		{
			printf("NIE");
		}
		else
		{
			for (auto j : o)
			{
				if (j != -1)
					printf("%d ", j);
			}
		}
		printf("\n");
	}
	return 0;
}