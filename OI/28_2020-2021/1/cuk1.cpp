// Jakub Daszkiewicz
// zadanie Cukiernia

#include <stdio.h>
#include <algorithm>

using namespace std;

struct gablota
{
    int d, p, r;
    bool operator<(const gablota& g)
    {
        return max(d, max(p, r)) < max(g.d, max(g.p, g.r));
    }
    bool operator>(gablota g)
    {
        return g < *this;
    }
    int min2()
    {
        return min(d + p, min(d + r, p + r));
    }
    int maxg()
    {
        return max(d, max(p, r));
    }
};

const gablota zero = {0, 0, 0};
const gablota gmax = {__INT_MAX__, __INT_MAX__, __INT_MAX__};

bool comp_d(gablota a, gablota b)
{
    if (a.p + a.r == b.p + b.r) return a.d > b.d;
    return a.p + a.r < b.p + b.r;
}

bool comp_p(gablota a, gablota b)
{
    if (a.d + a.r == b.d + b.r) return a.p > b.p;
    return a.d + a.r < b.d + b.r;
}

bool comp_r(gablota a, gablota b)
{
    if (a.p + a.d == b.p + b.d) return a.r > b.r;
    return a.p + a.d < b.p + b.d;
}

int main()
{
    int n;
    scanf("%d", &n);
    gablota g[n];
    bool zd = 0, zp = 0, zr = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d", &g[i].d, &g[i].p, &g[i].r);
        if (g[i].d) zd = 1;
        if (g[i].p) zp = 1;
        if (g[i].r) zr = 1;
    }
    long long a = 0;
    gablota* s;
    if (zd)
    {
        s = min_element(g, g+n, comp_d);
        a += (long long)(s -> p) + (long long)(s -> r);
        *s = gmax;
    }
    if (zp)
    {
        s = min_element(g, g+n, comp_p);
        a += (long long)(s -> d) + (long long)(s -> r);
        *s = gmax;
    }
    if (zr)
    {
        s = min_element(g, g+n, comp_r);
        a += (long long)(s -> p) + (long long)(s -> d);
        *s = gmax;
    }
    for (int i=0; i<n; i++)
    {
        a += (long long)g[i].min2();
    }
    printf("%lld", a);
    return 0;
}