// Jakub Daszkiewicz
// zadanie Cukiernia

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct gablota
{
    int d, p, r;
    bool operator<(const gablota &g)
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

bool comp_d(gablota a, gablota b)
{
    if (a.p + a.r == b.p + b.r)
        return a.d < b.d;
    return a.p + a.r > b.p + b.r;
}

bool comp_p(gablota a, gablota b)
{
    if (a.d + a.r == b.d + b.r)
        return a.p < b.p;
    return a.d + a.r > b.d + b.r;
}

bool comp_r(gablota a, gablota b)
{
    if (a.p + a.d == b.p + b.d)
        return a.r < b.r;
    return a.p + a.d > b.p + b.d;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<gablota> g;
    bool zd = 0, zp = 0, zr = 0;
    gablota inp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &inp.d, &inp.p, &inp.r);
        if (inp.d)
            zd = 1;
        if (inp.p)
            zp = 1;
        if (inp.r)
            zr = 1;
        g.push_back(inp);
    }
    long long a = 0;

    // zrobić sortowanie i popować zamiast min_element

    if (zd)
    {
        sort(g.begin(), g.end(), comp_d);
        a += (long long)(g.back().p) + (long long)(g.back().r);
        g.pop_back();
    }
    if (zp)
    {
        sort(g.begin(), g.end(), comp_p);
        a += (long long)(g.back().d) + (long long)(g.back().r);
        g.pop_back();
    }
    if (zr)
    {
        sort(g.begin(), g.end(), comp_r);
        a += (long long)(g.back().p) + (long long)(g.back().d);
        g.pop_back();
    }
    for (auto i : g)
    {
        a += (long long)i.min2();
    }
    printf("%lld", a);
    return 0;
}