// Jakub Daszkiewicz
// zadanie Kwiaciarnia

#include <stdio.h>
#include <algorithm>

using namespace std;

struct bunch
{
    int r, g, b;
};

bool comp_r(bunch b0, bunch b1)
{
    return (b0.r < b1.r);
}

bool comp_g(bunch b0, bunch b1)
{
    return (b0.g < b1.g);
}

bool comp_b(bunch b0, bunch b1)
{
    return (b0.b < b1.b);
}

int main()
{
    int r, g, b, n;
    scanf("%d %d %d %d", &r, &g, &b, &n);
    bunch f[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d", &f[i].r, &f[i].g, &f[i].b);
    }
    int rc = 0, gc = 0, bc = 0;
    bunch a;
    sort(f, f+n, comp_r);
    a.r = 0;
    a.g = 0;
    a.b = 0;
    for (int i=0; i<n; i++)
    {
        if (a.g + f[i].g > g) continue;
        else a.g += f[i].g;
        if (a.b + f[i].b > b) 
        {
            a.g -= f[i].g;
            continue;
        }
        else a.b += f[i].b;
        a.r += f[i].r;
        if (a.r > r) break;
        rc++;
    }
    sort(f, f+n, comp_g);
    a.r = 0;
    a.g = 0;
    a.b = 0;
    for (int i=0; i<n; i++)
    {
        if (a.r + f[i].r > r) continue;
        else a.r += f[i].r;
        if (a.b + f[i].b > b) 
        {
            a.r -= f[i].r;
            continue;
        }
        else a.b += f[i].b;
        a.g += f[i].g;
        if (a.g > g) break;
        gc++;
    }
    sort(f, f+n, comp_b);
    a.r = 0;
    a.g = 0;
    a.b = 0;
    for (int i=0; i<n; i++)
    {
        if (a.g + f[i].g > g) continue;
        else a.g += f[i].g;
        if (a.r + f[i].r > r) 
        {
            a.g -= f[i].g;
            continue;
        }
        else a.r += f[i].r;
        a.b += f[i].b;
        if (a.b > b) break;
        bc++;
    }
    printf("%d", min(rc, min(gc, bc)));
    return 0;
}