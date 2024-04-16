// Jakub Daszkiewicz
// zadanie Przelewy

#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n, s, t, a = 0;
	scanf("%d", &n);
	multiset<int> p;
	for (int i = 0; i < n; i++)
	{
		s = 0;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &t);
			s += t;
		}
		if (s)
			p.insert(s);
	}
	while (!p.empty())
	{
		a++;
		t = *p.begin() + *prev(p.end());
		p.erase(p.begin());
		p.erase(prev(p.end()));
		if (t)
			p.insert(t);
	}
	printf("%d", a);
	return 0;
}