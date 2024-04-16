// Jakub Daszkiewicz
// zadanie Dowolna linia

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>

#define ff first
#define ss second

using namespace std;

struct dist
{
    int xy, a, b;
    float p;
};

int cd(pair <int, int> p0, pair <int, int> p1)
{
    return abs(p0.ff - p1.ff) + abs(p0.ss - p1.ss);
}

float cp(pair <int, int> p0, pair <int, int> p1)
{
    return sqrt(abs(p0.ff - p1.ff) * abs(p0.ff - p1.ff) + abs(p0.ss - p1.ss) * abs(p0.ss - p1.ss));
}

bool sv(dist d0, dist d1)
{
    if (d0.xy == d1.xy) return d0.p > d1.p;
    return d0.xy > d1.xy;
}

int main()
{
    int n, a = 0;
    scanf("%d", &n);
    pair <int, int> p[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &p[i].ff, &p[i].ss);
    }
    vector <dist> d;
    dist t;
    // priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, /* greater <pair <int, pair <int, int>>> */aaaaaaaa> d;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            t.xy = cd(p[i], p[j]);
            t.a = i;
            t.b = j;
            t.p = cp(p[i], p[j]);
            d.push_back(t);
        }
    }
    sort(d.begin(), d.end(), sv);
    int b[n], bb[3], c[n], cn = 0, f, s;
    fill(c, c+n, 0);
    fill(b, b+n, 0);
    bb[0] = n;
    bb[1] = 0;
    bb[2] = 0;
    while (bb[0] != 0 || bb[1] != 2 || bb[2] != n-2)
    {
        // f = d[d.size()-1].ss.ff;
        // s = d[d.size()-1].ss.ss;
        f = d[d.size()-1].a;
        s = d[d.size()-1].b;
        if (b[f] < 2 && b[s] < 2 && !(b[f] == 1 && b[s] == 1 && c[f] == c[s]))
        {
            if (b[f] == 0 && b[s] == 0) 
            {
                cn++;
                c[f] = cn;
                c[s] = cn;
            }
            if (c[f] == 0 || c[s] == 0)
            {
                if (c[f] == 0) c[f] = c[s];
                else c[s] = c[f];
            }
            if (c[f] != c[s])
            {
                for (int i=0; i<n; i++)
                {
                    if (i == s) continue;
                    if (c[i] == c[s]) c[i] = c[f];
                }
                c[s] = c[f];
            }
            bb[b[f]]--;
            b[f]++;
            bb[b[f]]++;
            bb[b[s]]--;
            b[s]++;
            bb[b[s]]++;
            a += d[d.size()-1].xy;
        }
        d.pop_back();
    }
    printf("%d", a);
    return 0;
}