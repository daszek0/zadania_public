// Jakub Daszkiewicz
// zadanie Wyliczanka

#include <cstdio>

using namespace std;

const int N = 16;//1 << 21;
int tv[N], st = 1;

void ao(int f, int t)
{
	f += st, t += st;
	while (f < t)
	{
		if (f & 1)
		{
			tv[f]++;
			f >>= 1;
			f++;
		}
		else
			f >>= 1;
		if (t & 1)
			t >>= 1;
		else
		{
			tv[t]++;
			t >>= 1;
			t--;
		}
	}
	if (f == t)
	{
		tv[f]++;
	}
}

int ro(int n)
{
	n += st;
	int r = 0;
	while (n)
	{
		r += tv[n];
		n >>= 1;
	}
	return r;
}

int main()
{
	int n, k = 0, p;
	scanf("%d", &n);
	while (st < n)
		st <<= 1;
	for (int i = n + 1; i > 1; i--)
	{
		scanf("%d", &p);
		k += p;
		if (k >= i)
			k -= i;
		printf("%d ", k + ro(k) + 1);
		ao(k, n);
	}
	return 0;
}