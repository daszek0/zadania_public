// Jakub Daszkiewicz
// zadanie Kwiaciarnia

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int r, g, b, n;
    scanf("%d %d %d %d", &r, &g, &b, &n);
    int ro[n], go[n], bo[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d", &ro[i], &go[i], &bo[i]);
    }
    sort(ro, ro+n);
    sort(go, go+n);
    sort(bo, bo+n);
    int rc = 0, ra = 0, gc = 0, ga = 0, bc = 0, ba = 0;
    for (int i=0; i<n; i++)
    {
        ra += ro[i];
        if (ra > r) break;
        rc++;
    }
    for (int i=0; i<n; i++)
    {
        ga += go[i];
        if (ga > g) break;
        gc++;
    }
    for (int i=0; i<n; i++)
    {
        ba += bo[i];
        if (ba > b) break;
        bc++;
    }
    printf("%d", min(rc, min(gc, bc)));
    return 0;
}