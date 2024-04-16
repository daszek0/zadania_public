// Jakub Daszkiewicz
// zadanie Cukiernia

#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int n;

struct gablota
{
    int d, p, r;
    long long min2()
    {
        return (long long)min(d + p, min(d + r, p + r));
    }
    long long _r()
    {
        return d + p;
    }
    long long _p()
    {
        return d + r;
    }
    long long _d()
    {
        return p + r;
    }
};

struct mo
{
    int i = -1;
    long long v = __INT64_MAX__;
    long long im = __INT64_MAX__;
};

struct sum
{
    int d, p, r;
    long long s = __INT64_MAX__;
};

bool comp_sum(sum a, sum b)
{
    return a.s < b.s;
}

int main()
{
    scanf("%d", &n);
    gablota g[n + 3];
    g[n] = {0, 0, 0};
    g[n + 1] = {0, 0, 0};
    g[n + 2] = {0, 0, 0};
    bool z[3];
    z[0] = 0, z[1] = 0, z[2] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &g[i].d, &g[i].p, &g[i].r);
        if (g[i].d)
            z[0] = 1;
        if (g[i].p)
            z[1] = 1;
        if (g[i].r)
            z[2] = 1;
    }
    mo md[3], mp[3], mr[3];
    for (int i = 0; i < n; i++)
    {
        if (z[0] && g[i]._d() - g[i].min2() < md[0].im)
        {
            md[0].i = i;
            md[0].v = g[i]._d();
            md[0].im = g[i]._d() - g[i].min2();
        }
        if (z[1] && g[i]._p() - g[i].min2() < mp[0].im)
        {
            mp[0].i = i;
            mp[0].v = g[i]._p();
            mp[0].im = g[i]._p() - g[i].min2();
        }
        if (z[2] && g[i]._r() - g[i].min2() < mr[0].im)
        {
            mr[0].i = i;
            mr[0].v = g[i]._r();
            mr[0].im = g[i]._r() - g[i].min2();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (z[0] && i != md[0].i && g[i]._d() - g[i].min2() < md[1].im)
        {
            md[1].i = i;
            md[1].v = g[i]._d();
            md[1].im = g[i]._d() - g[i].min2();
        }
        if (z[1] && i != mp[0].i && g[i]._p() - g[i].min2() < mp[1].im)
        {
            mp[1].i = i;
            mp[1].v = g[i]._p();
            mp[1].im = g[i]._p() - g[i].min2();
        }
        if (z[2] && i != mr[0].i && g[i]._r() - g[i].min2() < mr[1].im)
        {
            mr[1].i = i;
            mr[1].v = g[i]._r();
            mr[1].im = g[i]._r() - g[i].min2();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (z[0] && i != md[1].i && i != md[0].i && g[i]._d() - g[i].min2() < md[2].im)
        {
            md[2].i = i;
            md[2].v = g[i]._d();
            md[2].im = g[i]._d() - g[i].min2();
        }
        if (z[1] && i != mp[1].i && i != mp[0].i && g[i]._p() - g[i].min2() < mp[2].im)
        {
            mp[2].i = i;
            mp[2].v = g[i]._p();
            mp[2].im = g[i]._p() - g[i].min2();
        }
        if (z[2] && i != mr[1].i && i != mr[0].i && g[i]._r() - g[i].min2() < mr[2].im)
        {
            mr[2].i = i;
            mr[2].v = g[i]._r();
            mr[2].im = g[i]._r() - g[i].min2();
        }
    }
    sum as[27];
    long long a = 0;
    int sk = 0;
    if (!z[0] && !z[1] && !z[2])
    {
        printf("0");
        return 0;
    }
    else if (z[0] && z[1] && z[2])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    as[9 * i + 3 * j + k].d = md[i].i;
                    as[9 * i + 3 * j + k].p = mp[j].i;
                    as[9 * i + 3 * j + k].r = mr[k].i;
                    if ((md[i].i == -1 && z[0]) || (mp[j].i == -1 && z[1]) || (mr[k].i == -1 && z[2])) continue;
                    as[9 * i + 3 * j + k].s = md[i].im + mp[j].im + mr[k].im;
                }
            }
        }
        sort(as, as + 27, comp_sum);
        for (int i = 0; i < 27; i++)
        {
            if (as[i].d != as[i].p && as[i].d != as[i].r && as[i].r != as[i].p)
            {
                sk = i;
                break;
            }
        }
    }
    else if (!z[0])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mp[i].i == -1 || mr[j].i == -1) continue;
                as[3 * i + j].p = mp[i].i;
                as[3 * i + j].r = mr[j].i;
                as[3 * i + j].s = mp[i].im + mr[j].im;
            }
        }
        sort(as, as + 9, comp_sum);
        for (int i = 0; i < 9; i++)
        {
            if (as[i].r != as[i].p)
            {
                sk = i;
                break;
            }
        }
    }
    else if (!z[1])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (md[i].i == -1 || mr[j].i == -1) continue;
                as[3 * i + j].d = md[i].i;
                as[3 * i + j].r = mr[j].i;
                as[3 * i + j].s = md[i].im + mr[j].im;
            }
        }
        sort(as, as + 9, comp_sum);
        for (int i = 0; i < 9; i++)
        {
            if (as[i].d != as[i].r)
            {
                sk = i;
                break;
            }
        }
    }
    else if (!z[2])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (z[0] && z[1])
                {
                    if (md[i].i == -1 || mp[j].i == -1) continue;
                    as[3 * i + j].d = md[i].i;
                    as[3 * i + j].p = mp[j].i;
                    as[3 * i + j].s = md[i].im + mp[j].im;
                }
            }
        }
        sort(as, as + 9, comp_sum);
        for (int i = 0; i < 9; i++)
        {
            if (as[i].d != as[i].p)
            {
                sk = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (z[0] && i == as[sk].d)
            a += g[i]._d();
        else if (z[1] && i == as[sk].p)
            a += g[i]._p();
        else if (z[2] && i == as[sk].r)
            a += g[i]._r();
        else
            a += g[i].min2();
    }
    printf("%lld", a);
    return 0;
}