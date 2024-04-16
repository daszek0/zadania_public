// Jakub Daszkiewicz
// zadanie Morskie opowieści

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[5000];

int bfs(int f, int t)
{
    int d[5000];
    fill(d, d + 5000, -1);
    queue<int> q;
    d[f] = 0;
    q.push(f);
    while (!q.empty())
    {
        for (auto i : g[q.front()])
        {
            if (d[i] == -1)
            {
                d[i] = d[q.front()] + 1;
                if (i == t)
                {
                    return d[i];
                }
                q.push(i);
            }
        }
        q.pop();
    }
    return d[t];
}

int main()
{
    int n, m, k, a, b, s, t, d;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d %d", &s, &t, &d);
        b = bfs(s - 1, t - 1);
        if (b == -1)
            printf("NIE\n");
        else if (s == t)
        {
            if (d % 2)
                printf("NIE\n");
            else
                printf("TAK\n");
        }
        else if ((d / b) % 2 == 0)
            printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}