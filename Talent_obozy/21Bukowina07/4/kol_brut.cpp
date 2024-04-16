// Jakub Daszkiewicz
// zadanie Koleje

#include <cstdio>
#include <algorithm>

using namespace std;

void qinp(int *n)
{
    int r = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();
    while (c >= '0' && c <= '9')
    {
        r = (r << 3) + (r << 1) + c - '0';
        c = getchar_unlocked();
    }
    *n = r;
}

int main()
{
	int n, m, z, b, e, l;
	// scanf("%d %d %d", &n, &m, &z);
	qinp(&n);
	qinp(&m);
	qinp(&z);
	int p[n], mp;
	fill(p, p + n, 0);
	for (int i = 0; i < z; i++)
	{
		// scanf("%d %d %d", &b, &e, &l);
		qinp(&b);
		qinp(&e);
		qinp(&l);
		// e--;
		mp = 0;
		for (int i = b; i < e; i++)
		{
			if (p[i] > mp)
				mp = p[i];
		}
		if (mp + l > m)
		{
			putchar_unlocked('N');
			putchar_unlocked('\n');
		}
		else
		{
			putchar_unlocked('T');
			putchar_unlocked('\n');
			for (int i = b; i < e; i++)
			{
				p[i] += l;
			}
		}
	}
	return 0;
}