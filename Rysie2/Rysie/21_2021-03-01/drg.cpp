// Jakub Daszkiewicz
// zadanie Drzewo genealogiczne

#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

bool pair_second_less(pair<int, int> p, pair<int, int> q)
{
	if (p.second == q.second)
		return p.first < q.first;
	return p.second < q.second;
}

int main()
{
	int n;
	scanf("%d", &n);
	int d[n + 1];
	pair<int, int> v[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i].first);
		v[i].second = i;
	}
	sort(v, v + n);
	for (int i = 0; i < n; i++)
	{
		v[i].first = i;
	}
	sort(v, v + n, pair_second_less);
	set<int> p;
	d[v[0].first] = 0;
	p.insert(v[0].first);
	d[n] = -__INT_MAX__ - 1;
	p.insert(n);
	for (int i = 1; i < n; i++)
	{
		d[v[i].first] = max(d[*p.lower_bound(v[i].first)], d[*prev(p.lower_bound(v[i].first))]) + 1;
		p.insert(v[i].first);
	}
	printf("%d", *max_element(d, d + n));
	return 0;
}