// Jakub Daszkiewicz
// zadanie Przedziały

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> p0, pair<int, int> p1)
{
	if (p0.first == p1.first)
	{
		return p0.second > p1.second;
	}
	else return p0.first < p1.first;
}

int main()
{
	int n, a, b;
	scanf("%d", &n);
	vector<pair<int, int>> e, r;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		e.push_back(make_pair(a, 1));
		e.push_back(make_pair(b, -1));
	}
	sort(e.begin(), e.end(), comp);
	a = 0;
	b = 0;
	for (auto i : e)
	{
		b += i.second;
		if (b == 1 && i.second == 1)
		{
			a++;
			r.push_back(make_pair(i.first, 0));
		}
		else if (b == 0 && i.second == -1)
		{
			r.back().second = i.first;
		}
	}
	for (int i = 1; i < r.size(); i++)
	{
		if (r[i - 1].second == r[i].first || r[i - 1].second == r[i].first - 1)
		{
			r[i - 1].second = r[i].second;
			r[i] = make_pair(0, 0);
			a--;
		}
	}
	printf("%d\n", a);
	for (auto i : r)
	{
		if (i.first != 0)
			printf("%d %d\n", i.first, i.second);
	}
	return 0;
}