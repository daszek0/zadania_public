// Jakub Daszkiewicz
// zadanie Restauracje

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define ff first
#define ss second

using namespace std;

vector <pair <int, int>> graph[1001];
int s[1001];

void dijkstra()
{
    priority_queue <pair <int, int>, vector<pair <int, int>>, greater <pair <int, int>>> q;
    // int x = 0;
    pair <int, int> cur;
    for (int i=0; i<graph[0].size(); i++)
    {
        q.push(graph[0][i]);
    }
    while (!q.empty())
    {
        cur = q.top();
        // x += cur.ff;
        if (s[cur.ss] == -1) s[cur.ss] = cur.ff;
        else s[cur.ss] = min(s[cur.ss], cur.ff);
        for (int i=0; i<graph[cur.ss].size(); i++)
        {
            if (graph[cur.ss][i].ss == cur.ss) continue;
            if (s[graph[cur.ss][i].ss] == -1 || s[graph[cur.ss][i].ss] > graph[cur.ss][i].ff + cur.ff)
            {
                q.push(make_pair(graph[cur.ss][i].ff + cur.ff, graph[cur.ss][i].ss));
            }
        }
        // x -= cur.ff;
        q.pop();
    }
}

int main()
{
    int n, k, m, t0, t1, t2, r = 0;
    fill(s, s+1001, -1);
    s[0] = 0;
    scanf("%d %d %d", &n, &k, &m);
    for (int i=0; i<k; i++)
    {
        scanf("%d", &t0);
        graph[t0].push_back(make_pair(0, 0));
        graph[0].push_back(make_pair(0, t0));
    }
    for (int i=0; i<m; i++)
    {
        scanf("%d %d %d", &t0, &t1, &t2);
        graph[t0].push_back(make_pair(t2, t1));
        graph[t1].push_back(make_pair(t2, t0));
    }
    dijkstra();
    for (int i=1; i<=n; i++)
    {
        r = max(r, s[i]);
    }
    printf("%d", r);
    return 0;
}