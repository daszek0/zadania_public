// Jakub Daszkiewicz
// zadanie Park trampolin

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1001;				// maksymalna krawędź tabeli
const long long M = 1000000007; // modulo
const int TS = 1 << 11;			// wielkość drzewa 2^11 = 2048

long long tv[N][TS]; // drzewa pionowo
long long th[N][TS]; // drzewa poziomo
int stv, sth;		 // zmniejszenie drzew

void a(long long tr[], int st, int f, int t, long long v)
{
	f += st;
	t += st;
	while (f < t)
	{
		if (f & 1)
		{
			tr[f] += v;
			if (tr[f] >= M)
			{
				tr[f] -= M;
			}
			// tr[f] %= M;
			f >>= 1;
			f++;
		}
		else
		{
			f >>= 1;
		}
		if (t & 1)
		{
			t >>= 1;
		}
		else
		{
			tr[t] += v;
			if (tr[t] >= M)
			{
				tr[t] -= M;
			}
			// tr[t] %= M;
			t >>= 1;
			t--;
		}
	}
	if (f == t)
	{
		tr[f] += v;
		if (tr[f] >= M)
		{
			tr[f] -= M;
		}
		// tr[f] %= M;
	}
}

long long r(long long tr[], int st, int n)
{
	long long r = 0;
	n += st;
	while (n)
	{
		r += tr[n];
		if (r >= M)
		{
			r -= M;
		}
		// r %= M;
		n >>= 1;
	}
	return r;
}

void qinp(int *n)
{
	int r = 0;
	char c = getchar_unlocked();
	while (c < '0' || c > '9')
		c = getchar_unlocked();
	while (c >= '0' && c <= '9')
	{
		r = (r << 3) + (r << 1) + c - '0';
		c = getchar_unlocked();
	}
	*n = r;
}

int main()
{
	int n, m;
	// scanf("%d %d", &n, &m);
	qinp(&n);
	qinp(&m);
	stv = 1;
	sth = 1;
	while (stv < n)
	{
		stv <<= 1;
	}
	stv++;
	while (sth < m)
	{
		sth <<= 1;
	}
	sth++;
	a(tv[1], stv, 1, 1, 1);
	int p;
	long long v;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			// scanf("%d", &p);
			qinp(&p);
			v = r(th[i], sth, j) + r(tv[j], stv, i);
			v %= M;
			a(th[i], sth, j + 1, min(j + p, m), v);
			a(tv[j], stv, i + 1, min(i + p, n), v);
		}
	}
	printf("%lld", (r(th[n], sth, m) + r(tv[m], stv, n)) % M);
	return 0;
}