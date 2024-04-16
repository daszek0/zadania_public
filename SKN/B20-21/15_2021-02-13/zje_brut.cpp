// Jakub Daszkiewicz
// zadanie Zjeżdżalnie

#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

vector<int> g[300001];

int bfs(int f, int t)
{
    vector<int> q;
    int d[300001];
    fill(d, d + 300001, 0);
    int c;
    q.push_back(f);
    d[f] = 1;
    while (!q.empty())
    {
        c = q.back();
        q.pop_back();
        for (auto i : g[c])
        {
            // if (d[i] == __INT_MAX__)
            // {
                q.push_back(i);
                if (d[i] < d[c] + 1)
                    d[i] = d[c] + 1;
                // if (i == t) return d[i];
            // }
        }
    }
    if (d[t] == 0) return -1;
    return d[t];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int h[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &h[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (h[i][j] > h[k][j])
                {
                    g[(i - 1) * m + j].push_back((k - 1) * m + j);
                }
            }
            for (int k = 1; k <= m; k++)
            {
                if (h[i][j] > h[i][k])
                {
                    g[(i - 1) * m + j].push_back((i - 1) * m + k);
                }
            }
        }
    }
    printf("%d", bfs(1, n * m));
    return 0;
}