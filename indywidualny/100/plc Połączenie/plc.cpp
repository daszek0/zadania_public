// Jakub Daszkiewicz
// zadanie Połączenie

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector <pair <int, int>> graph[4002];
int s[4002];

void dijkstra()
{
    priority_queue <pair <int, int>, vector<pair <int, int>>, greater <pair <int, int>>> q;
    pair <int, int> cur;
    for (int i=0; i<graph[0].size(); i++)
    {
        q.push(graph[0][i]);
    }
    while (!q.empty())
    {
        cur = q.top();
        if (s[cur.second] == -1) s[cur.second] = cur.first;
        else s[cur.second] = min(s[cur.second], cur.first);
        for (int i=0; i<graph[cur.second].size(); i++)
        {
            if (graph[cur.second][i].second == cur.second) continue;
            if (s[graph[cur.second][i].second] == -1 || s[graph[cur.second][i].second] > graph[cur.second][i].first + cur.first)
            {
                q.push(make_pair(graph[cur.second][i].first + cur.first, graph[cur.second][i].second));
            }
        }
        q.pop();
    }
}

int main()
{
    fill(s, s+4002, -1);
    map <pair <int, int>, int> m;
    int n, index;
    pair <int, int> tp;
    scanf("%d %d", &tp.first, &tp.second);
    m[tp] = 0;
    scanf("%d %d", &tp.first, &tp.second);
    if (m.find(tp) != m.end())
    {
        printf("0");
        return 0;
    }
    m[tp] = 1;
    index = 2;
    scanf("%d", &n);
    int ti0, ti1;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &tp.first, &tp.second);
        if (m.find(tp) == m.end())
        {
            m[tp] = index;
            ti0 = index;
            index++;
        }
        else
        {
            ti0 = m[tp];
        }
        scanf("%d %d", &tp.first, &tp.second);
        if (m.find(tp) == m.end())
        {
            m[tp] = index;
            ti1 = index;
            index++;
        }
        else
        {
            ti1 = m[tp];
        }
        graph[ti0].push_back(make_pair(10, ti1));
        graph[ti1].push_back(make_pair(10, ti0));
    }
    dijkstra();
    if (s[1] == -1) printf("NIE");
    else printf("%d", s[1]);
    return 0;
}