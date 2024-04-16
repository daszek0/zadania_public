// Jakub Daszkiewicz
// zadanie Wielokąty

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	pair<long long, long long> pn[n + 1], pm[m + 1];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld %lld", &pn[i].first, &pn[i].second);
	}
	pn[n] = pn[0];
	for (int i = 0; i < m; i++)
	{
		scanf("%lld %lld", &pm[i].first, &pm[i].second);
	}
	pm[m] = pm[0];
	int np = 0, mp = 0;
	pair<long long, long long> l = make_pair(__INT64_MAX__, __INT64_MAX__);
	for (int i = 0; i < n; i++)
	{
		if (pn[i] < l)
		{
			l = pn[i];
			np = i;
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (pm[i] < l)
		{
			l = pm[i];
			mp = i;
		}
	}
	vector<pair<long long, long long>> rp;
	rp.push_back(make_pair(0, 0));
	for (int i = 0; i < n + m - 1; i++)
	{
		if ((pn[np + 1].first - pn[np].first) * (pm[mp + 1].second - pm[mp].second) < (pm[mp + 1].first - pm[mp].first) * (pn[np + 1].second - pn[np].second))
        {
			rp.push_back(make_pair(rp.back().first + pn[np + 1].first - pn[np].first, rp.back().second + pn[np + 1].second - pn[np].second));
            np++;
            if (np == n)
				np = 0;
        }
        else
        {
			rp.push_back(make_pair(rp.back().first + pm[mp + 1].first - pm[mp].first, rp.back().second + pm[mp + 1].second - pm[mp].second));
            mp++;
            if (mp == m)
				mp = 0;
        }
	}
	rp.push_back(rp[0]);
	rp.push_back(rp[1]);
	long long r = 0;
	for (auto i = next(rp.begin()); i != prev(rp.end()); i++)
	{
		r += i->first * (next(i)->second - prev(i)->second);
	}
	printf("%lld", abs(r));
	return 0;
}