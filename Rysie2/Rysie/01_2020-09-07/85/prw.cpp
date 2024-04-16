
// Jakub Daszkiewicz
// zadanie Prostokątne wyspy

#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

struct rect
{
	int x, y, h, w;
};

struct event
{
	int x, s, e, v;
};

bool event_x(event e0, event e1)
{
	return e0.x < e1.x;
}

const int N = 1 << 18;
const int R = 1 << 19;
int tree[R];
int st = 1;

void change(int s, int e)
{
	s += st;
	e += st;
	while (s < e)
	{
		if (s & 1)
		{
			tree[s] ^= 1;
			s >>= 1;
			s++;
		}
		else s >>= 1;
		if (e & 1) e >>= 1;
		else
		{
			tree[e] ^= 1;
			e >>= 1;
			e--;
		}
	}
	if (s == e)
	{
		tree[s] ^= 1;
	}
}

bool check(int i)
{
	bool r = 0;
	i += st;
	while (i)
	{
		r ^= tree[i];
		i >>= 1;
	}
	return r;
}

int main()
{
    int n, a = 0;
    scanf("%d", &n);
    rect inp;
	int y[n << 1];
	event e[n << 1];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d %d", &inp.x, &inp.y, &inp.w, &inp.h);
		y[2*i] = inp.y;
		y[2*i+1] = inp.y + inp.h;
		e[2*i].x = inp.x;
		e[2*i].s = inp.y;
		e[2*i].e = inp.y + inp.h;
		e[2*i].v = 1;
		e[2*i+1].x = inp.x + inp.w;
		e[2*i+1].s = inp.y;
		e[2*i+1].e = inp.y + inp.h;
		e[2*i+1].v = -1;
    }
	sort(e, e+(n << 1), event_x);
	sort(y, y+(n << 1));
    map <int, int> my;
	int ind = 1;
	my[y[0]] = 1;
	for (int i=1; i<(n << 1); i++)
	{
		if (y[i] != y[i-1])
		{
			ind++;
			my[y[i]] = ind;
		}
	}
	while (st < ind)
	{
		st <<= 1;
	}
	st--;
	for (int i=0; i<(n << 1); i++)
	{
		change(my[e[i].s], my[e[i].e]);
		if (e[i].v == 1 && check(my[e[i].s])) a++;
	}
	printf("%d", a);
    return 0;
}