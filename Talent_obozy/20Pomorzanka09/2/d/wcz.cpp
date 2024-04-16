// Jakub Daszkiewicz
// zadanie Wycieczka

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

struct edge
{
    float logd; // logarytm z odległości
    ll d; // odległość (zmodulowana)
    int dn; // wierzchołek na końcu krawędzi
    bool operator > (const edge& ad) const
    {
        return logd > ad.logd;
    }
};

const ll mod = 1000000007;

vector <pair <int, int>> g[300001]; // graf
ll dist[300001];
pair <float, int> tp;

edge me(float logd, ll d, int dn)
{
    edge ret;
    ret.logd = logd;
    ret.d = d;
    ret.dn = dn;
    return ret;
}

void dijkstra()
{
    // priority_queue <pair <pair <int, int>, int>, vector <pair <pair <int, int>, int>>, greater <pair <pair <int, int>, int>>> q; // kolejka do dijkstry
    priority_queue <edge, vector <edge>, greater <edge>> q; // kolejka do dijkstry
    q.push(me((float)0, 1, 1));
    edge cur; // bieżąco rozpatrywane połączenie
    while (!q.empty())
    {
        cur = q.top();
        q.pop();
        if (dist[cur.dn] == 0)
        {
            dist[cur.dn] = cur.d % mod;
            if (cur.logd > tp.ff)
            {
                tp.ff = cur.logd;
                tp.ss = cur.dn;
            }
        }
        for (unsigned i=0; i<g[cur.dn].size(); i++)
        {
            if (g[cur.dn][i].ss == cur.dn) continue;
            if (dist[g[cur.dn][i].ss] == 0) q.push(me(cur.logd + log(g[cur.dn][i].ff), (cur.d * g[cur.dn][i].ff) % mod, g[cur.dn][i].ss));
        }
    }
}

int main()
{
    int n; // liczba wierzchołków
    int m; // liczba połączeń
    scanf("%d %d", &n, &m);
    int h[n + 1]; // wysokość szczytu (wierzchołka)
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &h[i]);
    }
    int t0, t1; // zmienne pomocnicze
    for (int i=0; i<m; i++)
    {
        scanf("%d %d", &t0, &t1);
        g[t0].pb(mp(abs(h[t0] - h[t1]), t1));
        g[t1].pb(mp(abs(h[t0] - h[t1]), t0));
    }
    dijkstra();
    printf("%lld", dist[tp.ss]);
    return 0;
}