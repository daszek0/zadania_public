// Jakub Daszkiewicz
// zadanie Mydło Filozoficzne

#include <stdio.h>
#include <vector>
#include <algorithm>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 100000;
vector<pair<int, int>> g[N];     // graf
vector<int> l;                   // liście
pair<int, vector<int>> e[N - 1]; // krawędź (długość i liście)
long long d[N];                  // czasy dojścia do wierzchołka
int v[N];                        // odwiedzone do dfsa numerującego

void dfsd(int n, long long cd)
{
    d[n] = cd;
    for (auto it : g[n])
    {
        if (d[it.ff] == -1)
            dfsd(it.ff, cd + e[it.ss].ff);
    }
}

void dfsn(int n, int f, int ce)
{
    v[n] = 1;
    for (auto it : g[n])
    {
        if (!v[0] && !v[it.ff])
            dfsn(it.ff, f, it.ss);
    }
    if (v[0] && n != f)
    {
        e[ce].ss.pb(f);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %d", &a, &b, &e[i].ff);
        a--;
        b--;
        g[a].pb(mp(b, i));
        g[b].pb(mp(a, i));
    }
    for (int i = 1; i < n; i++)
    {
        if (g[i].size() == 1)
            l.pb(i);
    }
    fill(d, d + N, -1);
    dfsd(0, 0);
    for (auto it : l)
    {
        fill(v, v + N, 0);
        dfsn(it, it, g[it][0].ss);
    }
    int m;
    scanf("%d", &m);
    long long c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        a--;
        c = b - e[a].ff;
        e[a].ff = b;
        for (auto it : e[a].ss)
        {
            d[it] += c;
        }
        c = 0;
        for (auto it : l)
        {
            c = max(c, d[it]);
        }
        printf("%lld\n", c);
    }
    return 0;
}