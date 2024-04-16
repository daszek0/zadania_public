// Jakub Daszkiewicz
// zadanie Samochodziki

#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, p, a = 0;
	scanf("%d %d %d", &n, &k, &p);
	int c[p], f[k], of[n], pc = 0;
	set<int> l[n];
	fill(of, of + n, 0);
	for (int i = 0; i < p; i++)
	{
		scanf("%d", &c[i]);
		c[i]--;
		l[c[i]].insert(i);
	}
	for (int i = 0; i < k; i++)
	{
		if (of[c[pc]] == 0)
		{
			f[i] = c[pc];
			of[c[pc]] = 1;
			a++;
		}
		pc++;
	}
	int tc, no;
	for (int i = pc; i < p; i++)
	{
		if (of[c[i]] == 0)
		{
			tc = -1;
			no = -1;
			for (int j = 0; j < k; j++)
			{
				if (l[f[j]].upper_bound(i) == l[f[j]].end())
				{
					tc = j;
					break;
				}
				else if (*l[f[j]].upper_bound(i) > no)
				{
					no = *l[f[j]].upper_bound(i);
					tc = j;
				}
			}
			of[f[tc]] = 0;
			of[c[i]] = 1;
			f[tc] = c[i];
			a++;
		}
	}
	printf("%d", a);
	return 0;
}