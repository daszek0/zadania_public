// Jakub Daszkiewicz
// zadanie Czekolada

// test 6 4 2 1 3 1 4 4 1 2 => 42

#include <stdio.h>

using namespace std;

int main()
{
	int m, n, t;
	unsigned long long r = 0;
	scanf("%d %d", &m, &n);
	int x[1001] = {0}, y[1001] = {0};
	for (int i=0; i<m-1; ++i)
	{
		scanf("%d", &t);
		++x[t];
	}
	for (int i=0; i<n-1; ++i)
	{
		scanf("%d", &t);
		++y[t];
	}
	int xm = 1, ym = 1;
	for (int i=1000; i>0; --i)
	{
		while (x[i] > 0)
		{
			r += i*xm;
			--x[i];
			++ym;
		}
		while (y[i] > 0)
		{
			r += i*ym;
			--y[i];
			++xm;
		}
	}
	printf("%llu", r);
	return 0;
}
