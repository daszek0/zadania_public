// Jakub Daszkiewicz
// zadanie Literki

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <int> pos['Z' - 'A' + 1];
int lu['Z' - 'A' + 1];
char nj[1000001], nm[1000001];

int tree[1 << 21];
int st = 1;

void io(int s, int e)
{
	s += st;
	e += st;
	while (s < e)
	{
		if (s & 1)
		{
			tree[s] += 1;
			s >>= 1;
			s++;
		}
		else s >>= 1;
		if (e & 1) e >>= 1;
		else
		{
			tree[e] += 1;
			e >>= 1;
			e--;
		}
	}
	if (s == e)
	{
		tree[s] += 1;
	}
}

int ro(int i)
{
	int r = 0;
	i += st;
	while (i)
	{
		r += tree[i];
		i >>= 1;
	}
	return r;
}

int ml(char c, int p)
{
    int rp = -1;
    // for (; lu[c - 'A']<pos[c - 'A'].size(); lu[c - 'A']++)
    while (rp < p)
    {
        lu[c - 'A']++;
        rp = pos[c - 'A'][lu[c - 'A']] + ro(pos[c - 'A'][lu[c - 'A']]);
        if (rp == p) return 0;
        // if (rp >= p) break;
    }
    // rp = min(rp, n - 1);
    // io(0, rp - 1);
    io(0, rp - ro(pos[c - 'A'][lu[c - 'A']]));
    return rp - p;
}

int main()
{
    fill(lu, lu + 'Z' - 'A' + 1, -1);
    long long a = 0;
    scanf("%d", &n);
    while (st < n) st <<= 1;
    st++;
    char c;
    for (int i=0; i<n; i++)
    {
        c = getchar_unlocked();
        while (c < 'A' || c > 'Z') c = getchar_unlocked();
        pos[c - 'A'].push_back(i);
        nj[i] = c;
    }
    // scanf("%s", nj);
    scanf("%s", nm);
    for (int i=0; i<n; i++)
    {
        a += ml(nm[i], i);
    }
    printf("%lld", a);
    return 0;
}