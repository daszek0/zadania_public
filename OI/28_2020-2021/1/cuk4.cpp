// Jakub Daszkiewicz
// zadanie Cukiernia

#include <stdio.h>
#include <algorithm>

using namespace std;

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

struct kol
{
    int di = -1, pi = -1, ri = -1; // numer gablotki
    int d = 0, p = 0, r = 0;
    long long dv = __INT64_MAX__, pv = __INT64_MAX__, rv = __INT64_MAX__; // wartość
    long long s()
    {
        return ((di == -1) ? 0 : dv) + ((pi == -1) ? 0 : pv) + ((ri == -1) ? 0 : rv);
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    gablota g[n];
    bool zd = 0, zp = 0, zr = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &g[i].d, &g[i].p, &g[i].r);
        if (g[i].d)
            zd = 1;
        if (g[i].p)
            zp = 1;
        if (g[i].r)
            zr = 1;
    }
    kol dpr, drp, pdr, prd, rdp, rpd;
    for (int i = 0; i < n; i++)
    {
        if (zd && (g[i].d > dpr.d || (g[i].d == dpr.d && g[i]._d() < dpr.dv))) // (zd && (g[i]._d() < dpr.dv || (g[i]._d() == dpr.dv && g[i].d > g[dpr.d].d)))
        {
            dpr.di = i;
            dpr.d = g[i].d;
            dpr.dv = g[i]._d();
        }
        if (zd && (g[i].d > drp.d || (g[i].d == drp.d && g[i]._d() < drp.dv)))
        {
            drp.di = i;
            drp.d = g[i].d;
            drp.dv = g[i]._d();
        }
        if (zp && (g[i].p > pdr.p || (g[i].p == pdr.p && g[i]._p() < pdr.pv)))
        {
            pdr.pi = i;
            pdr.p = g[i].p;
            pdr.pv = g[i]._p();
        }
        if (zp && (g[i].p > prd.p || (g[i].p == prd.p && g[i]._p() < prd.pv)))
        {
            prd.pi = i;
            prd.p = g[i].p;
            prd.pv = g[i]._p();
        }
        if (zr && (g[i].r > rdp.r || (g[i].r == rdp.r && g[i]._r() < rdp.rv)))
        {
            rdp.ri = i;
            rdp.r = g[i].r;
            rdp.rv = g[i]._r();
        }
        if (zr && (g[i].r > rpd.r || (g[i].r == rpd.r && g[i]._r() < rpd.rv)))
        {
            rpd.ri = i;
            rpd.r = g[i].r;
            rpd.rv = g[i]._r();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (zp && i != dpr.di && (g[i].p > dpr.p || (g[i].p == dpr.p && g[i]._p() < dpr.pv)))
        {
            dpr.pi = i;
            dpr.p = g[i].p;
            dpr.pv = g[i]._p();
        }
        if (zr && i != drp.di && (g[i].r > drp.r || (g[i].r == drp.r && g[i]._r() < drp.rv)))
        {
            drp.ri = i;
            drp.r = g[i].r;
            drp.rv = g[i]._r();
        }
        if (zd && i != pdr.pi && (g[i].d > pdr.d || (g[i].d == pdr.d && g[i]._d() < pdr.dv)))
        {
            pdr.di = i;
            pdr.d = g[i].d;
            pdr.dv = g[i]._d();
        }
        if (zr && i != prd.pi && (g[i].r > prd.r || (g[i].r == prd.r && g[i]._r() < prd.rv)))
        {
            prd.ri = i;
            prd.r = g[i].r;
            prd.rv = g[i]._r();
        }
        if (zd && i != rdp.ri && (g[i].d > rdp.d || (g[i].d == rdp.d && g[i]._d() < rdp.dv)))
        {
            rdp.di = i;
            rdp.d = g[i].d;
            rdp.dv = g[i]._d();
        }
        if (zp && i != rpd.ri && (g[i].p > rpd.p || (g[i].p == rpd.p && g[i]._p() < rpd.pv)))
        {
            rpd.pi = i;
            rpd.p = g[i].p;
            rpd.pv = g[i]._p();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (zr && i != dpr.di && i != dpr.pi && (g[i].r > dpr.r || (g[i].r == dpr.r && g[i]._r() < dpr.rv)))
        {
            dpr.ri = i;
            dpr.r = g[i].r;
            dpr.rv = g[i]._r();
        }
        if (zp && i != drp.di && i != drp.ri && (g[i].p > drp.p || (g[i].p == drp.p && g[i]._p() < drp.pv)))
        {
            drp.pi = i;
            drp.p = g[i].p;
            drp.pv = g[i]._p();
        }
        if (zr && i != pdr.pi && i != pdr.di && (g[i].r > pdr.r || (g[i].r == pdr.r && g[i]._r() < pdr.rv)))
        {
            pdr.ri = i;
            pdr.r = g[i].r;
            pdr.rv = g[i]._r();
        }
        if (zd && i != prd.pi && i != prd.ri && (g[i].d > prd.d || (g[i].d == prd.d && g[i]._d() < prd.dv)))
        {
            prd.di = i;
            prd.d = g[i].d;
            prd.dv = g[i]._d();
        }
        if (zp && i != rdp.ri && i != rdp.di && (g[i].p > rdp.p || (g[i].p == rdp.p && g[i]._p() < rdp.pv)))
        {
            rdp.pi = i;
            rdp.p = g[i].p;
            rdp.pv = g[i]._p();
        }
        if (zd && i != rpd.ri && i != rpd.pi && (g[i].d > rpd.d || (g[i].d == rpd.d && g[i]._d() < rpd.dv)))
        {
            rpd.di = i;
            rpd.d = g[i].d;
            rpd.dv = g[i]._d();
        }
    }
    kol *sk = &dpr;
    long long a = dpr.s();
    if (drp.s() < a)
    {
        a = drp.s();
        sk = &drp;
    }
    if (pdr.s() < a)
    {
        a = pdr.s();
        sk = &pdr;
    }
    if (prd.s() < a)
    {
        a = prd.s();
        sk = &prd;
    }
    if (rdp.s() < a)
    {
        a = rdp.s();
        sk = &rdp;
    }
    if (rpd.s() < a)
    {
        a = rpd.s();
        sk = &rpd;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != sk->di && i != sk->pi && i != sk->ri)
            a += g[i].min2();
    }
    printf("%lld", a);
    return 0;
}