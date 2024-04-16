// Jakub Daszkiewicz
// zadanie Obrazy

#include <stdio.h>
#include <vector>
#include <algorithm>

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
    
    return 0;
}