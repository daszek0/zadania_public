// Jakub Daszkiewicz
// zadanie Chodnik

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

#define x first
#define y second

using namespace std;

bool pair_second(pair <int, int> a, pair <int, int> b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    // scanf("%d", &n);
    cin >> n;
    pair <int, int> t[n];
    set <pair <int, int>> ts;
    for (int i=0; i<n; i++)
    {
        // scanf("%d %d", &t[i].x, &t[i].y);
        cin >> t[i].x >> t[i].y;
        ts.insert(t[i]);
    }
    sort(t, t+n, pair_second);
    map <int, int> my;
    int yc = 1;
    for (int i=0; i<n; i++)
    {
        if (my.count(t[i].y) == 0)
        {
            my[t[i].y] = yc;
            yc++;
        }
    }
    sort(t, t+n);
    map <int, int> mx;
    int xc = 1;
    for (int i=0; i<n; i++)
    {
        if (mx.count(t[i].x) == 0)
        {
            mx[t[i].x] = xc;
            xc++;
        }
    }
    map <int, int> vdp[xc];
    for (int i=1; i<xc; i++)
    {
        vdp[i][0] = 0;
    }
    for (int i=0; i<n; i++)
    {
        vdp[mx[t[i].x]][my[t[i].y]] = prev(vdp[mx[t[i].x]].end())->second + 1;
    }
    sort(t, t+n, pair_second);
    map <int, int> hdp[yc];
    for (int i=1; i<yc; i++)
    {
        hdp[i][0] = 0;
    }
    for (int i=0; i<n; i++)
    {
        hdp[my[t[i].y]][mx[t[i].x]] = prev(hdp[my[t[i].y]].end())->second + 1;
    }
    int p;
    // scanf("%d", &p);
    cin >> p;
    int x0, x1, y0, y1, x0m, x1m, y0m, y1m, a = 0;
    for (int i=0; i<p; i++)
    {
        a = 0;
        // scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
        cin >> x0 >> y0 >> x1 >> y1;
        x0m = prev(mx.upper_bound(x0))->second;
        x1m = prev(mx.upper_bound(x1))->second;
        y0m = prev(my.upper_bound(y0))->second;
        y1m = prev(my.upper_bound(y1))->second;
        if (mx.find(x0) != mx.end()) a += prev(vdp[x0m].upper_bound(y1m))->second - prev(vdp[x0m].upper_bound(y0m))->second;
        if (mx.find(x1) != mx.end()) a += prev(vdp[x1m].upper_bound(y1m))->second - prev(vdp[x1m].upper_bound(y0m))->second;
        if (my.find(y0) != my.end()) a += prev(hdp[y0m].upper_bound(x1m))->second - prev(hdp[y0m].upper_bound(x0m))->second;
        if (my.find(y1) != my.end()) a += prev(hdp[y1m].upper_bound(x1m))->second - prev(hdp[y1m].upper_bound(x0m))->second;
        if (ts.count(make_pair(x0, y0))) a++;
        if (ts.count(make_pair(x1, y1))) a--;
        // printf("%d\n", a);
        cout << a << "\n";
    }
    return 0;
}