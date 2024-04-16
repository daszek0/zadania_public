// Jakub Daszkiewicz
// zadanie Drabina

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

using namespace std;

vector <pair <int, int>> graph[1000001];

int dijkstra(int start, int finish)
{
    if (start == finish) return 0;
    priority_queue <pair <int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int s[1000001];
    fill(s, s+1000001, -1);
    s[start] = 0;
    for (int i=0; i<graph[start].size(); i++)
    {
        q.push(graph[start][i]);
        s[graph[start][i].ss] = graph[start][i].ff;
    }
    while (!q.empty()/* s[finish] == -1 */)
    {
        for (int i=0; i<graph[q.top().ss].size(); i++)
        {
            auto curr = graph[q.top().ss][i];
            if (s[curr.ss] == -1 || s[curr.ss] > curr.ff + q.top().ff)
            {
                s[curr.ss] = curr.ff + q.top().ff;
                q.push(mp(curr.ff + q.top().ff, curr.ss));
            }
        }
        q.pop();
    }
    return s[finish];
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int t;
    for (int i=1; i<n; i++)
    {
        scanf("%d", &t);
        graph[2*i-1].pb(mp(t, 2*i+1));
    }
    for (int i=1; i<n; i++)
    {
        scanf("%d", &t);
        graph[2*i].pb(mp(t, 2*i+2));
    }
    for (int i=1; i<n+1; i++)
    {
        scanf("%d", &t);
        graph[2*i].pb(mp(t, 2*i-1));
        graph[2*i-1].pb(mp(t, 2*i));
    }
    char qt;
    int a, b, c;
    for (int i=0; i<q; i++)
    {
        scanf("%c", &qt);
        while (qt != 'Z' && qt != 'P') scanf("%c", &qt);
        if (qt == 'Z')
        {
            scanf("%d %d %d", &a, &b, &c);
            if (abs(a - b) == 1)
            {
                for (int j=0; j<graph[a].size(); j++)
                {
                    if (graph[a][j].ss == b)
                    {
                        graph[a][j].ff = c;
                        break;
                    }
                }
                for (int j=0; j<graph[b].size(); j++)
                {
                    if (graph[b][j].ss == a)
                    {
                        graph[b][j].ff = c;
                        break;
                    }
                }
            }
            else
            {
                if (a > b) swap(a, b);
                for (int j=0; j<graph[a].size(); j++)
                {
                    if (graph[a][j].ss == b)
                    {
                        graph[a][j].ff = c;
                        break;
                    }
                }
            }
        }
        else
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", dijkstra(a, b));
        }
    }
    return 0;
}