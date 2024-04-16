// Jakub Daszkiewicz
// zadanie Przelewy

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n, s, t, a = 0;
	scanf("%d", &n);
	deque<int> p;
	for (int i = 0; i < n; i++)
	{
		s = 0;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &t);
			s += t;
		}
		// printf("%d ", s);
		if (s)
			p.push_back(s);
	}
	// printf("\n");
	sort(p.begin(), p.end());
	while (!p.empty())
	{
		if (abs(p.front()) > abs(p.back()))
		{
			a++;
			p.front() += p.back();
			p.pop_back();
			if (p.front() == 0)
			{
				p.pop_front();
			}
			sort(p.begin(), p.end());
		}
		else
		{
			a++;
			p.back() += p.front();
			p.pop_front();
			if (p.back() == 0)
			{
				p.pop_back();
			}
			sort(p.begin(), p.end());
		}
	}
	printf("%d", a);
	return 0;
}