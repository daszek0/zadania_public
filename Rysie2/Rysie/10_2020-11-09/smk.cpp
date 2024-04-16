// Jakub Daszkiewicz
// zadanie Teleporty i smoki

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

#define x first
#define y second

using namespace std;

vector<int> g[1000001];

int bfs(int f, int t)
{
    queue<int> q;
    int d[1000001];
    fill(d, d + 1000001, __INT_MAX__);
    int c;
    q.push(f);
    d[f] = 0;
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        for (auto i : g[c])
        {
            if (d[i] == __INT_MAX__)
            {
                q.push(i);
                d[i] = d[c] + 1;
                if (i == t) return d[i];
            }
        }
    }
    return -1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char t[1001][1001];
    for (int i = 0; i < 1001; i++)
        t[0][i] = 'S';
    for (int i = 1; i < 1001; i++)
        t[i][0] = 'S';
    pair<int, int> s, e;
    scanf("%d %d %d %d", &s.y, &s.x, &e.y, &e.x);
    for (int i = 1; i <= n; i++)
        scanf("%s", t[i] + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (t[i][j] == 'S') continue;
            if (t[i - 1][j] == '.')
            {
                g[i * n + j].push_back((i - 1) * n + j);
                g[(i - 1) * n + j].push_back(i * n + j);
            }
            if (t[i][j - 1] == '.')
            {
                g[i * n + j].push_back(i * n + (j - 1));
                g[i * n + (j - 1)].push_back(i * n + j);
            }
        }
    }
    int tt;
    scanf("%d", &tt);
    pair<int, int> t0, t1;
    for (int i = 0; i < tt; i++)
    {
        scanf("%d %d %d %d", &t0.y, &t0.x, &t1.y, &t1.x);
        g[t0.x * n + t0.y].push_back(t1.x * n + t1.y);
    }
    printf("%d", bfs(s.x * n + s.y, e.x * n + e.y));
    return 0;
}