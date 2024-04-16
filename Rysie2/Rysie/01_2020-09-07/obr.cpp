// Jakub Daszkiewicz
// zadanie Obrazy

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int main()
{
    int n;
    int xd, yd, xg, yg;
    vector <pair <int, pair <pair <int, int>, int>>> h, v;
    // map <int, int> mx, my;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d %d", &xd, &yd, &xg, &yg);
        xd += 10000;
        yd += 10000;
        xg += 10000;
        yg += 10000;
        // mx[xd] = 0;
        // mx[xg] = 0;
        // my[yd] = 0;
        // my[yg] = 0;
        h.pb(mp(yd, mp(mp(xd, xg), 1)));
        h.pb(mp(yg, mp(mp(xd, xg), -1)));
        v.pb(mp(xd, mp(mp(yd, yg), 1)));
        v.pb(mp(xg, mp(mp(yd, yg), -1)));
    }
    // int id = 0;
    // for (auto I: mx)
    // {
    //     mx[I.F] = id;
    //     id++;
    // }
    // id = 0;
    // for (auto I: my)
    // {
    //     my[I.F] = id;
    //     id++;
    // }
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    int hu[20000], vu[20000];
    fill(hu, hu+20000, 0);
    fill(vu, vu+20000, 0);
    int rh = 0, rv = 0;
    for (int i=0; i<h.size(); i++)
    {
        // rh += abs(h[i].S.F.F - h[i].S.F.S) * h[i].S.S;
        for (int j=min(h[i].S.F.F, h[i].S.F.S); j<max(h[i].S.F.F, h[i].S.F.S); j++)
        {
            if (h[i].S.S == 1)
            {
                if (hu[j] == 0) rh++;
                hu[j]++;
            }
            else
            {
                hu[j]--;
            }
        }
    }
    for (int i=0; i<v.size(); i++)
    {
        // rh += abs(h[i].S.F.F - h[i].S.F.S) * h[i].S.S;
        for (int j=min(v[i].S.F.F, v[i].S.F.S); j<max(v[i].S.F.F, v[i].S.F.S); j++)
        {
            if (v[i].S.S == 1)
            {
                if (vu[j] == 0) rv++;
                vu[j]++;
            }
            else
            {
                vu[j]--;
            }
        }
    }
    // for (int i=0; i<v.size(); i++)
    // {
    //     rv += abs(v[i].S.F.F - v[i].S.F.S) * v[i].S.S;
    // }
    printf("%d", 2*(rh + rv));
    return 0;
}