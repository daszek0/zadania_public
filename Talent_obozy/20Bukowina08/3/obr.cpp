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

int query(int w, int v)
{
    if (w >= 1 << 15) return bool(tree[w]);
	else return query(w*2,v) + query(w*2 + 1, v);
}

// ogólnie to miał być przedziałowiec ale coś nie pykło

/* void add(int p, int s, int e, int x, int y, int v)
{
	// if (s<y || e>x) return;
	if (x>=s && y<=e)
	{
		tree[p]+=v * (y-x);
		// return;
        add(p*2,s,(s+e)/2,x,y,v);
	    add(p*2+1,(s+e)/2+1,e,x,y,v);
	}
	
} */

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
        // add(1, 1 << 15, (1 << 16) - 1, h[i].S.F.F + (1 << 15), h[i].S.F.S + (1 << 15), h[i].S.S);
        for (int j=h[i].S.F.F + (1 << 15); j<h[i].S.F.S + (1 << 15); j++) tree[j] += h[i].S.S;
        q = query(1, 1);
        rh += abs(p - q);
        p = q;
    }
    fill(tree, tree + (1 << 16), 0);
    p = 0;
    for (int i=0; i<v.size(); i++)
    {
        // add(1, 1 << 15, (1 << 16) - 1, v[i].S.F.F + (1 << 15), v[i].S.F.S + (1 << 15), v[i].S.S);
        for (int j=v[i].S.F.F + (1 << 15); j<v[i].S.F.S + (1 << 15); j++) tree[j] += v[i].S.S;
        q = query(1, 1);
        rv += abs(p - q);
        p = q;
    }
    printf("%d", rh+rv);
    return 0;
}