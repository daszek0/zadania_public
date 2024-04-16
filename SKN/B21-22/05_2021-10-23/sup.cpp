// Jakub Daszkiewicz
// zadanie Superliczby w permutacji

#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

const int N = 6;
int p[N], d[N];
vector<int> g[N], gr[N];
bitset<N> a;

void sd(int n, int cd)
{
	d[n] = max(d[n], cd);
	for (auto i : gr[n])
	{
		sd(i, cd + 1);
	}
}

bool ga(int n, int s, int d)
{
	bool r = false;
	for (auto i : g[n])
	{
		r = max(r, ga(i, s, d + 1));
		// if (r)
		// 	break;
	}
	if (d == s)
	{
		r = true;
	}
	if (r)
	{
		a[p[n]] = 1;
	}
	return r;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		// in[p[i]] = i;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i] < p[j])
			{
				g[i].push_back(j);
				gr[j].push_back(i);
			}
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		sd(i, 1);
	}
	a.reset();
	int m = *max_element(d, d + N);
	for (int i = 0; i < n; i++)
	{
		if (d[i] == m)
		{
			ga(i, m, 1);
		}
	}
	printf("%lu\n", a.count());
	for (int i = 1; i <= n; i++)
	{
		if (a[i])
		{
			printf("%d ", i);
		}
	}
	return 0;
}