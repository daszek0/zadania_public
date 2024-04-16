// Jakub Daszkiewicz
// zadanie Słoiki

#include <stdio.h>

using namespace std;

int tree[1 << 19];
int st = 1;

void update(int n)
{
    n += st;
    while (n)
    {
        tree[n] ^= 1;
        n >>= 1;
    }
}

int query(int s, int e)
{
    int r = 0;
	s += st;
	e += st;
	while (s < e)
	{
		if (s & 1)
		{
            r ^= tree[s];
			s >>= 1;
			s++;
		}
		else s >>= 1;
		if (e & 1) e >>= 1;
		else
		{
            r ^= tree[e];
			e >>= 1;
			e--;
		}
	}
	if (s == e)
	{
		r ^= tree[s];
	}
    return r;
}

int main()
{
    int n, m, r;
    scanf("%d %d", &n, &m);
    while (st < n)
    {
        st <<= 1;
    }
    st++;
    int t;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        if (t % 2) update(i);
    }
    for (int i=0; i<m; i++)
    {
        r = 0;
        scanf("%d", &t);
        t--;
        update(t);
        for (int i=0; i<n; i++)
        {
            for (int j=i; j<n; j++)
            {
                if (!query(i, j)) r++;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}