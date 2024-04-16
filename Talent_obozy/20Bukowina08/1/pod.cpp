// Jakub Daszkiewicz
// zadanie Podróż

#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct connection
{
    int t;
    int a;
    int T;
    int d;
};

connection mc(int t, int a, int T, int d)
{
    connection r;
    r.t = t;
    r.a = a;
    r.T = T;
    r.d = d;
    return r;
}

vector <connection> graph[1000];
int now;
int times[1000];

void dijkstra(int start)
{
    priority_queue <pair <int, int>/* , vector <pair <int, int>>, greater <vector <pair <int, int>>> */> q;
    // priority_queue <int, vector <int>, greater <vector <int>>> q;
    for (int i=0; i<graph[start].size(); i++)
    {
        auto curr = graph[start][i];
        q.push(make_pair(-(now + curr.t + ((now + curr.a) % curr.T)), curr.d));
    }
    while (!q.empty())
    {
        times[q.top().second] = min(times[q.top().second], -q.top().first);
        for (int i=0; i<graph[q.top().second].size(); i++)
        {
            if (graph[q.top().second][i].d == q.top().second) continue;
            auto curr = graph[q.top().second][i];
            q.push(make_pair( -( -(q.top().first) + now + curr.t + ((now + curr.a) % curr.T)), curr.d));
        }
        q.pop();
    }
}

int main()
{
    fill(times, times+1000, 2147483647);
    int n, k, s, d, h, m;
    scanf("%d %d %d %d %d %d", &n, &k, &s, &d, &h, &m);
    now = h * 60 + m;
    int stops, T, t0, t1;
    connection t;
    for (int i=0; i<k; i++)
    {
        scanf("%d %d", &stops, &T);
        int stop[stops];
        for (int j=0; j<stops; j++)
        {
            scanf("%d", &stop[j]);
        }
        int time[stops-1];
        for (int j=0; j<stops-1; j++)
        {
            scanf("%d", &time[j]);
        }
        t0 = 0;
        for (int j=0; j<stops-1; j++)
        {
            t.d = stop[j+1];
            t.t = time[j];
            t.T = T;
            t.a = t0;
            t0 += time[j];
            graph[stop[j]].push_back(t);
        }
        t0 = 0;
        for (int j=stops-2; j>=0; j--)
        {
            t.d = stop[j];
            t.t = time[j];
            t.T = T;
            t.a = t0;
            t0 += time[j];
            graph[stop[j]].push_back(t);
        }
        // t0 = 0;
        // for (int j=1; j<stops; j++)
        // {
        //     scanf("%d", &t1);
        //     t.t = t1;
        //     t.a = t0;
        //     t0 += t1;
        //     t.T = T;
        // }
    }
    dijkstra(s);
    printf("%d %d", (times[d] / 60) % 24, times[d] % 60);
    
    return 0;
}