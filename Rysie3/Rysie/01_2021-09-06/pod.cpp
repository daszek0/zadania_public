// Jakub Daszkiewicz
// zadanie Podział zamku

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> g[200001];
int sts[200001];
int a = __INT_MAX__;

void cst(int n, int p)
{
	for (auto i : g[n])
	{
		if (i != p)
		{
			cst(i, n);
		}
	}
	sts[p] += sts[n] + 1;
	a = min(a, abs(N - sts[n] - 1 - sts[n] - 1));
}

int main()
{
	scanf("%d", &N);
	int t0, t1;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &t0, &t1);
		t0--;
		t1--;
		g[t0].push_back(t1);
		g[t1].push_back(t0);
	}
	cst(1, 0);
	printf("%d", a);
	return 0;
}