// Jakub Daszkiewicz
// zadanie Chodnik

#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>

#define x first
#define y second

using namespace std;

bool pair_second(pair <long long, long long> a, pair <long long, long long> b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    pair <long long, long long> t[n];
    set <pair <long long, long long>> ts;
    for (long long i=0; i<n; i++)
    {
        scanf("%lld %lld", &t[i].x, &t[i].y);
        ts.insert(t[i]);
    }
    sort(t, t+n, pair_second);
    map <long long, long long> my;
    long long yc = 1;
    for (long long i=0; i<n; i++)
    {
        if (my.count(t[i].y) == 0)
        {
            my[t[i].y] = yc;
            yc++;
        }
    }
    sort(t, t+n);
    map <long long, long long> mx;
    long long xc = 1;
    for (long long i=0; i<n; i++)
    {
        if (mx.count(t[i].x) == 0)
        {
            mx[t[i].x] = xc;
            xc++;
        }
    }
    map <long long, long long> vdp[xc];
    for (long long i=0; i<xc; i++)
    {
        vdp[i][0] = 0;
    }
    for (long long i=0; i<n; i++)
    {
        vdp[mx[t[i].x]][my[t[i].y]] = prev(vdp[mx[t[i].x]].end(), 1)->second + 1;
    }
    sort(t, t+n, pair_second);
    map <long long, long long> hdp[yc];
    for (long long i=0; i<yc; i++)
    {
        hdp[i][0] = 0;
    }
    for (long long i=0; i<n; i++)
    {
        hdp[my[t[i].y]][mx[t[i].x]] = prev(hdp[my[t[i].y]].end(), 1)->second + 1;
    }
    long long p;
    scanf("%lld", &p);
    long long x0, x1, y0, y1, x0m, x1m, y0m, y1m, a = 0;
    for (long long i=0; i<p; i++)
    {
        a = 0;
        scanf("%lld %lld %lld %lld", &x0, &y0, &x1, &y1);
        x0m = prev(mx.upper_bound(x0))->second;
        x1m = prev(mx.upper_bound(x1))->second;
        y0m = prev(my.upper_bound(y0))->second;
        y1m = prev(my.upper_bound(y1))->second;
        if (mx.count(x0)) a += prev(vdp[x0m].upper_bound(y1m))->second - prev(vdp[x0m].upper_bound(y0m))->second;
        if (mx.count(x1)) a += prev(vdp[x1m].upper_bound(y1m))->second - prev(vdp[x1m].upper_bound(y0m))->second;
        if (mx.count(y0)) a += prev(hdp[y0m].upper_bound(x1m))->second - prev(hdp[y0m].upper_bound(x0m))->second;
        if (mx.count(y1)) a += prev(hdp[y1m].upper_bound(x1m))->second - prev(hdp[y1m].upper_bound(x0m))->second;
        if (ts.count(make_pair(x1, y1))) a--;
        printf("%lld\n", a);
    }
    return 0;
}