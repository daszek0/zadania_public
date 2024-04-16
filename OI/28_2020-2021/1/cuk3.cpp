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
    int d = -1, p = -1, r = -1;                                           // numer gablotki
    long long dv = __INT64_MAX__, pv = __INT64_MAX__, rv = __INT64_MAX__; // wartość
    long long s()
    {
        return ((d == -1) ? 0 : dv) + ((p == -1) ? 0 : pv) + ((r == -1) ? 0 : rv);
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
        if (zd && (g[i]._d() < dpr.dv || (g[i]._d() == dpr.dv && g[i].d > g[dpr.d].d)))
        {
            dpr.d = i;
            dpr.dv = g[i]._d();
        }
        if (zd && (g[i]._d() < drp.dv || (g[i]._d() == drp.dv && g[i].d > g[drp.d].d)))
        {
            drp.d = i;
            drp.dv = g[i]._d();
        }
        if (zp && (g[i]._p() < pdr.pv || (g[i]._p() == pdr.pv && g[i].p > g[pdr.p].p)))
        {
            pdr.p = i;
            pdr.pv = g[i]._p();
        }
        if (zp && (g[i]._p() < prd.pv || (g[i]._p() == prd.pv && g[i].p > g[prd.p].p)))
        {
            prd.p = i;
            prd.pv = g[i]._p();
        }
        if (zr && (g[i]._r() < rdp.rv || (g[i]._r() == rdp.rv && g[i].r > g[rdp.r].r)))
        {
            rdp.r = i;
            rdp.rv = g[i]._r();
        }
        if (zr && (g[i]._r() < rpd.rv || (g[i]._r() == rpd.rv && g[i].r > g[rpd.r].r)))
        {
            rpd.r = i;
            rpd.rv = g[i]._r();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (zp && i != dpr.d && (g[i]._p() < dpr.pv || (g[i]._p() == dpr.pv && g[i].p > g[dpr.p].p)))
        {
            dpr.p = i;
            dpr.pv = g[i]._p();
        }
        if (zr && i != drp.d && (g[i]._r() < drp.rv || (g[i]._r() == drp.rv && g[i].r > g[drp.r].r)))
        {
            drp.r = i;
            drp.rv = g[i]._r();
        }
        if (zd && i != pdr.p && (g[i]._d() < pdr.dv || (g[i]._d() == pdr.dv && g[i].d > g[pdr.d].d)))
        {
            pdr.d = i;
            pdr.dv = g[i]._d();
        }
        if (zr && i != prd.p && (g[i]._r() < prd.rv || (g[i]._r() == prd.rv && g[i].r > g[prd.r].r)))
        {
            prd.r = i;
            prd.rv = g[i]._r();
        }
        if (zd && i != rdp.r && (g[i]._d() < rdp.dv || (g[i]._d() == rdp.dv && g[i].d > g[rdp.d].d)))
        {
            rdp.d = i;
            rdp.dv = g[i]._d();
        }
        if (zp && i != rpd.r && (g[i]._p() < rpd.pv || (g[i]._p() == rpd.pv && g[i].p > g[rpd.p].p)))
        {
            rpd.p = i;
            rpd.pv = g[i]._p();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (zr && i != dpr.d && i != dpr.p && (g[i]._r() < dpr.rv || (g[i]._r() == dpr.rv && g[i].r > g[dpr.r].r)))
        {
            dpr.r = i;
            dpr.rv = g[i]._r();
        }
        if (zp && i != drp.d && i != drp.r && (g[i]._p() < drp.pv || (g[i]._p() == drp.pv && g[i].p > g[drp.p].p)))
        {
            drp.p = i;
            drp.pv = g[i]._p();
        }
        if (zr && i != pdr.p && i != pdr.d && (g[i]._r() < pdr.rv || (g[i]._r() == pdr.rv && g[i].r > g[pdr.r].r)))
        {
            pdr.r = i;
            pdr.rv = g[i]._r();
        }
        if (zd && i != prd.p && i != prd.r && (g[i]._d() < prd.dv || (g[i]._d() == prd.dv && g[i].d > g[prd.d].d)))
        {
            prd.d = i;
            prd.dv = g[i]._d();
        }
        if (zp && i != rdp.r && i != rdp.d && (g[i]._p() < rdp.pv || (g[i]._p() == rdp.pv && g[i].p > g[rdp.p].p)))
        {
            rdp.p = i;
            rdp.pv = g[i]._p();
        }
        if (zd && i != rpd.r && i != rpd.p && (g[i]._d() < rpd.dv || (g[i]._d() == rpd.dv && g[i].d > g[rpd.d].d)))
        {
            rpd.d = i;
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
        if (i != sk->d && i != sk->p && i != sk->r)
            a += g[i].min2();
    }
    printf("%lld", a);
    return 0;
}