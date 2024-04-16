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

int main()
{
    int n;
    scanf("%d", &n);
    gablota g[2] = {{__INT32_MAX__, __INT32_MAX__, __INT32_MAX__}, {__INT32_MAX__, __INT32_MAX__, __INT32_MAX__}};
    gablota* mg;
    gablota inp;
    bool zd = 0, zp = 0, zr = 0;
    long long a = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d", &inp.d, &inp.p, &inp.r);
        if (inp.d) zd = 1;
        if (inp.p) zp = 1;
        if (inp.r) zr = 1;
        mg = max_element(g, g+2);
        if (inp < *mg) *mg = inp;
        a += inp.min2();
    }
    int zg = -1;
    if (!zd)
    {
        if (g[0].maxg() - g[0].d < g[1].maxg() - g[0].d)
        {
            a += g[0].maxg() - g[0].d;
            zg = 1;
        }
        else
        {
            a += g[1].maxg() - g[1].d;
            zg = 0;
        }
    }
    if (!zp)
    {
        if (zg == -1)
        {
            if (g[0].maxg() - g[0].p < g[1].maxg() - g[0].p)
            {
                a += g[0].maxg() - g[0].p;
                zg = 1;
            }
            else
            {
                a += g[1].maxg() - g[1].p;
                zg = 0;
            }
        }
        else
        {
            a += g[zg].maxg() - g[zg].p;
        }
    }
    if (!zr)
    {
        if (zg == -1)
        {
            if (g[0].maxg() - g[0].r < g[1].maxg() - g[0].r)
            {
                a += g[0].maxg() - g[0].r;
                zg = 1;
            }
            else
            {
                a += g[1].maxg() - g[1].p;
                zg = 0;
            }
        }
        else
        {
            a += g[zg].maxg() - g[zg].r;
        }
    }
    printf("%lld", a);
    return 0;
}