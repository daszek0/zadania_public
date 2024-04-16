// Jakub Daszkiewicz
// zadanie Drzewo genealogiczne

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int t[1 << 24], mi = 0;

void add(int n, int i)
{
	if (t[i] == 0)
	{
		t[i] = n;
		mi = max(mi, i);
		return;
	}
	if (n < t[i])
		add(n, i << 1);
	else
		add(n, (i << 1) + 1);
}

int main()
{
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		add(a, 1);
	}
	printf("%d", (int)log2((double)mi));
	return 0;
}