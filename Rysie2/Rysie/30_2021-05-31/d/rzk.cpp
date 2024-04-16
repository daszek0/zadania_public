// Jakub Daszkiewicz
// zadanie Rzeka

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	long long n, m, ans, a, b;
	scanf("%lld %lld", &n, &m);
	ans = m;
	vector<pair<long long, long long>> e, r;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld %lld", &a, &b);
		if (a > b)
		{
			e.push_back(make_pair(a, 1));
			e.push_back(make_pair(b, -1));
		}
	}
	sort(e.begin(), e.end(), greater<pair<long long, long long>>());
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
	for (auto i : r)
	{
		ans += (i.first - i.second) << 1;
	}
	printf("%lld", ans);
	return 0;
}