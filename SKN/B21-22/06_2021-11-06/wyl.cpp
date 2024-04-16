// Jakub Daszkiewicz
// zadanie Wyliczanka

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 16; //1 << 21;
int tv[N], st = 1;

void dp(int n)
{
	n += st;
	while (n)
	{
		tv[n]++;
		n >>= 1;
	}
}

int cd(int f, int t)
{
	f += st, t += st;
	int r = 0;
	while (f < t)
	{
		if (f & 1)
		{
			r += tv[f];
			f >>= 1;
			f++;
		}
		else
			f >>= 1;
		if (t & 1)
			t >>= 1;
		else
		{
			r += tv[t];
			t >>= 1;
			t--;
		}
	}
	if (f == t)
	{
		r += tv[f];
	}
	return r;
}

int main()
{
	int n, k = 0, p;
	scanf("%d", &n);
	while (st < n)
		st <<= 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p);
		k += p + cd(k, min(k + p, n));
		if (k + p >= n)
		{
			p -= n - k + cd(k, n);
			k = p + cd(0, p);
		}
		else
		{
		}
		// if (k >= n)
		// 	k -= n;
		dp(k);
		printf("%d ", ++k);
	}
	return 0;
}