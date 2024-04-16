// Jakub Daszkiewicz
// zadanie Dwuszereg

#include <cstdio>
#include <unordered_set>

using namespace std;

int n, r1[50000], r2[50000], c[50000], a1[100001], a2[100001], cr[50000][2], nc[100001], a;
unordered_set<int> f;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &r1[i]);
		a1[r1[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &r2[i]);
		a2[r2[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (a1[r1[i]] == 2)
		{
			c[i]++;
			cr[i][0] = r1[i];
			nc[r1[i]] = 1;
		}
		if (a2[r2[i]] == 2)
		{
			c[i]++;
			cr[i][1] = r2[i];
			nc[r2[i]] = 1;
		}
		if (c[i] == 1)
		{
			f.insert(max(cr[i][0], cr[i][1]));
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (c[i] == 2 && (f.count(cr[i][0]) || f.count(cr[i][1])))
		{
			a1[r1[i]]--;
			a2[r1[i]]++;
			a2[r2[i]]--;
			a1[r2[i]]++;
			nc[r1[i]] = 0;
			nc[r2[i]] = 0;
			swap(r1[i], r2[i]);
			c[i] = 0;
			a++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (c[i] == 2 && nc[r1[i]] && nc[r2[i]])
		{
			a1[r1[i]]--;
			a2[r1[i]]++;
			a2[r2[i]]--;
			a1[r2[i]]++;
			nc[r1[i]] = 0;
			nc[r2[i]] = 0;
			swap(r1[i], r2[i]);
			c[i] = 0;
			a++;
		}
	}
	printf("%d", a);
	return 0;
}