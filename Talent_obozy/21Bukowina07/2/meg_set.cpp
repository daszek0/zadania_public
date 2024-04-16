// Jakub Daszkiewicz
// zadanie Megalopolis

#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int n, m, a, b, on[250001];
vector<int> no;
char c;
vector<int> g[250001];
set<int> e;
int es[250001];

int tree[1 << 19], st = 1;

void nn(int n, int p, int d)
{
	on[n] = no.size();
	no.push_back(n);
	for (auto i : g[n])
	{
		if (i != p)
		{
			nn(i, n, d + 1);
			es[n] += es[i];
		}
	}
	if (g[n].size() < 2)
	{
		e.insert(on[n]);
		es[n]++;
	}
	tree[st + on[n]] = d;
}

void nh(int a, int b)
{
	if (a > b)
		swap(a, b);
	a += st;
	b += st;
	while (a < b)
	{
		if (a & 1)
		{
			tree[a]--;
			a >>= 1;
			a++;
		}
		else
			a >>= 1;
		if (b & 1)
			b >>= 1;
		else
		{
			tree[b]--;
			b >>= 1;
			b--;
		}
	}
	if (a == b)
		tree[a]--;
}

int check(int p)
{
	int r = 0;
	p += st;
	while (p)
	{
		r += tree[p];
		p >>= 1;
	}
	return r;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	while (st < n)
	{
		st <<= 1;
	}
	nn(1, -1, 0);
	scanf("%d", &m);
	set<int>::iterator t;
	for (int i = 0; i < n + m - 1; i++)
	{
		scanf("\n%c", &c);
		if (c == 'A') // zamiana
		{
			scanf("%d %d", &a, &b);
			a = max(on[a], on[b]);
			t = e.lower_bound(a);
			for (int i = 0; i < es[no[a]] - 1; i++)
				t++;
			nh(a, *t);
		}
		else // zapytanie
		{
			scanf("%d", &a);
			printf("%d\n", check(on[a]));
		}
	}
	return 0;
}