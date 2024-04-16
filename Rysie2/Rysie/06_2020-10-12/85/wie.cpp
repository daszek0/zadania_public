// Jakub Daszkiewicz
// zadanie Wielokąty

#include <stdio.h>
#include <algorithm>

#define ff first
#define ss second

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    pair <int, int> a[n + 1], b[m + 1];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &a[i].ff, &a[i].ss);
    }
    a[n] = a[0];
    for (int i=0; i<m; i++)
    {
        scanf("%d %d", &b[i].ff, &b[i].ss);
    }
    b[m] = b[0];
    int ac, bc;
    pair <int, int> l = make_pair(__INT_MAX__, __INT_MAX__);
    for (int i=0; i<n; i++)
    {
        if (a[i] < l)
        {
            l = a[i];
            ac = i;
        }
    }
    l = make_pair(__INT_MAX__, __INT_MAX__);
    for (int i=0; i<m; i++)
    {
        if (b[i] < l)
        {
            l = b[i];
            bc = i;
        }
    }
    pair <int, int> rn[m + n + 2];
    rn[0] = make_pair(0, 0);
    for (int i=1; i<m+n; i++)
    {
        if ((long long)(a[ac + 1].ff - a[ac].ff) * (long long)(b[bc + 1].ss - b[bc].ss) < (long long)(b[bc + 1].ff - b[bc].ff) * (long long)(a[ac + 1].ss - a[ac].ss))
        {
            rn[i] = make_pair(rn[i - 1].ff + a[ac + 1].ff - a[ac].ff, rn[i - 1].ss + a[ac + 1].ss - a[ac].ss);
            ac++;
            if (ac == n) ac = 0;
        }
        else
        {
            rn[i] = make_pair(rn[i - 1].ff + b[bc + 1].ff - b[bc].ff, rn[i - 1].ss + b[bc + 1].ss - b[bc].ss);
            bc++;
            if (bc == m) bc = 0;
        }
    }
    rn[n+m] = rn[0];
    rn[n+m+1] = rn[1];
    long long r = 0;
    for (int i=1; i<m+n; i++)
    {
        r += (long long)rn[i].ff * (long long)(rn[i + 1].ss - rn[i - 1].ss);
    }
    printf("%lld", abs(r));
    return 0;
}