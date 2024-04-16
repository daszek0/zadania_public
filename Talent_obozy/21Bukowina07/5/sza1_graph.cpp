// Jakub Daszkiewicz
// zadanie Przeskocz szachownicę!

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct bignum
{
	vector<char> d;
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

const int N = 100;
vector<pair<int, int>> g[N][N];	 // graf
vector<pair<int, int>> gr[N][N]; // odwrócony graf
int v[N][N];					 // odwiedzone
bignum a = {{1}};

// bignum itb(int n) // int na bignum
// {
// 	bignum r;
// 	r.d.clear();
// 	while (n)
// 	{
// 		r.d.push_back(n % 10);
// 		n /= 10;
// 	}
// 	return r;
// }

void grg(pair<int, int> n) // generowanie odwróconego grafu
{
	v[n.first][n.second] = 1;
	for (auto i : g[n.first][n.second])
	{
		if (!v[i.first][i.second])
		{
			grg(i);
		}
		gr[i.first][i.second].push_back(n);
	}
}

void cr(pair<int, int> f) // obliczanie liczby dróg
{
	// v[n.first][n.second] = 1;
	// if (n.first != 0 && n.second != 0)
	// 	a += itb(gr[n.first][n.second].size() - 1);
	// for (auto i : gr[n.first][n.second])
	// {
	// 	if (!v[i.first][i.second])
	// 	{
	// 		cr(i);
	// 	}
	// }
	queue<pair<int, int>> n;
	n.push(f);
	while (!n.empty())
	{
		if (gr[n.front().first][n.front().second].size())
			n.push(gr[n.front().first][n.front().second][0]);
		for (int i = 1; i < gr[n.front().first][n.front().second].size(); i++)
		{
			n.push(gr[n.front().first][n.front().second][i]);
			++a;
		}
		n.pop();
	}
}

int main()
{
	int n; // wielkość szachownicy
	scanf("%d", &n);
	int t; // wczytywanie
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &t);
			if (t == 0)
				continue;
			if (i + t < n)
			{
				g[i][j].push_back(make_pair(i + t, j));
			}
			if (j + t < n)
			{
				g[i][j].push_back(make_pair(i, j + t));
			}
		}
	}
	grg(make_pair(0, 0));
	if (!v[n - 1][n - 1])
	{
		printf("0\n");
		return 0;
	}
	// fill(&v[0][0], &v[N - 1][N - 1] + 1, 0);
	cr(make_pair(n - 1, n - 1));
	a.write();
	return 0;
}