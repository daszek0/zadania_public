// Jakub Daszkiewicz
// zadanie Zasięg

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

#define x first
#define y second
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

vector <pair <int, int>> g[302];

double dist(pair <int, int> p0, pair <int, int> p1)
{
    return sqrt((abs(p0.x - p1.x) * abs(p0.x - p1.x)) + (abs(p0.y - p1.y) * abs(p0.y - p1.y)));
}

int dijkstra(int from, int to)
{
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;
    int d[303];
    fill(d, d+303, -1);
    q.push(mp(0, from));
    pair <int, int> cur;
    while (!q.empty())
    {
        cur = q.top();
        d[cur.ss] = cur.ff;
        if (cur.ss == to) return cur.ff;
        for (unsigned i=0; i<g[cur.ss].size(); i++)
        {
            if (g[cur.ss][i].ss == cur.ss) continue;
            if (d[g[cur.ss][i].ss] == -1) q.push(make_pair(cur.ff + g[cur.ss][i].ff, g[cur.ss][i].ss));
        }
        q.pop();
    }
    return d[to];
}

int main()
{
    int r;
    scanf("%d", &r);
    pair <int, int> s, e;
    scanf("%d %d", &s.x, &s.y);
    scanf("%d %d", &e.x, &e.y);
    int ta;
    scanf("%d", &ta);
    pair <int, int> t[ta+2];
    t[0] = s;
    t[ta+1] = e;
    for (int i=1; i<ta+1; i++)
    {
        scanf("%d %d", &t[i].x, &t[i].y);
    }
    int d;
    for (int i=0; i<ta+2; i++)
    {
        for (int j=i+1; j<ta+2; j++)
        {
            if (dist(t[i], t[j]) >= (r << 1))
            {
                d = ceil((dist(t[i], t[j]) - (r << 1)) / (r << 1));
            }
            else d = 0;
            g[i].pb(mp(d, j));
            g[j].pb(mp(d, i));
        }
    }
    printf("%d", dijkstra(0, ta+1));
    return 0;
}