// Jakub Daszkiewicz
// zadanie Obrazy

#include <stdio.h>
#include <algorithm>
#include <vector>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int tree[1 << 16];

void query (int w, int val)
{
	wynik+=tree[w]; // dodajemy do wyniku to co dodawalismy do jego przedzialu
	if (w==1) return; // jesli to korzen nie wywolujemy sie dalej
	else query(w/2,val); // rekurencyjnie dla ojca
}

void add (int w, int p, int k, int x, int y, int val)
{
	if (k<x || p>y) return;
	if (x<=p && y>=k)
	{
		tree[w]+=val;
		return;
	}
	add(w*2,p,(p+k)/2,x,y,val);
	add(w*2,(p+k)/2+1,k,x,y,val);
}

int main()
{
    int n;
    vector <pair <int, pair <pair <int, int>, int>>> h;
    vector <pair <int, pair <pair <int, int>, int>>> v;
    int xd, yd, xg, yg;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d %d", &xd, &yd, &xg, &yg);
        xd += 10000;
        yd += 10000;
        xg += 10000;
        yg += 10000;
        h.pb(mp(yd, mp(mp(xd, xg), 1)));
        h.pb(mp(yg, mp(mp(xd, xg), -1)));
        v.pb(mp(xd, mp(mp(yd, yg), 1)));
        v.pb(mp(xg, mp(mp(yd, yg), -1)));
    }
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    int p = 0, rh = 0, rv = 0, q;
    for (int i=0; i<h.size(); i++)
    {
        add(1, 1 << 15, (1 << 16) - 1, h[i].S.F.F + (1 << 15), h[i].S.F.S + (1 << 15), h[i].S.S);
        q = tree[1];
        rh += abs(p - q);
        p = q;
    }
    fill(tree, tree + (1 << 16), 0);
    p = 0;
    for (int i=0; i<v.size(); i++)
    {
        add(1, 1 << 15, (1 << 16) - 1, v[i].S.F.F + (1 << 15), v[i].S.F.S + (1 << 15), v[i].S.S);
        q = tree[1];
        rv += abs(p - q);
        p = q;
    }
    printf("%d", rh+rv);
    return 0;
}