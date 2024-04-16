// Jakub Daszkiewicz
// zadanie Ustawienie robotów

#include <stdio.h>
#include <algorithm>

#define ff first
#define ss second

using namespace std;

bool comp_ff(pair <int, int> p0, pair <int, int> p1)
{
    if (p0.ff == p1.ff) return comp_ss(p0, p1);
    return p0.ff < p1.ff;
}

bool comp_ss(pair <int, int> p0, pair <int, int> p1)
{
    if (p0.ss == p1.ss) return comp_ff(p0, p1);
    return p0.ss < p1.ss;
}

int main()
{
    int n;
    scanf("%d", &n);
    pair <int, int> r[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &r[i].ff, &r[i].ss);
    }
    sort(r, r+n, comp_ff);
    
    return 0;
}