// Jakub Daszkiewicz
// zadanie Czekolada

#include <stdio.h>

using namespace std;

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int t, x[1001], y[1001];
	for (int i=0; i<1001; i++)
	{
		x[i] = 0;
		y[i] = 0;
	}
	for (int i=0; i<m-1; i++)
	{
		scanf("%d", &t);
		x[t]++;
	}
	for (int i=0; i<n-1; i++)
	{
		scanf("%d", &t);
		y[t]++;
	}
	int mx = 1, my = 1;
	long long r = 0;
	for (int i=1000; i>0; i--)
	{
		while (x[i] > 0)
		{
			r += i*mx;
			my++;
			x[i]--;
		}
		while (y[i] > 0)
		{
			r += i*my;
			mx++;
			y[i]--;
		}
	}
	printf("%lld\n", r);
	return 0;
}
