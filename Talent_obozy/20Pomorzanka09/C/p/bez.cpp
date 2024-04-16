// Jakub Daszkiewicz
// zadanie Bezpieczna komnata

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define mp make_pair
#define ff first
#define ss second

using namespace std;

const int N = 200001;
vector <int> g[N];
int d[N];

void bfs(int n)
{
    queue <pair <int, int>> q;
    int v[N];
    fill(v, v+N, 0);
    q.push(mp(n, -1));
    v[n] = 1;
    pair <int, int> cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        d[cur.ff] = cur.ss;
        // v[cur.ff] = 1;
        for (auto i: g[cur.ff])
        {
            if (!v[i])
            {
                q.push(mp(i, cur.ss + 1));
                v[i] = 1;
            }
        }
    }
}

int main()
{
    fill(d, d+N, 21372137);
    int n;
    scanf("%d", &n);
    int t0, t1;
    for (int i=1; i<n; i++)
    {
        scanf("%d %d", &t0, &t1);
        g[t0].push_back(t1);
        g[t1].push_back(t0);
    }
    for (int i=1; i<n + 1; i++)
    {
        if (g[i].size() == 1)
        {
            g[i].push_back(0);
            g[0].push_back(i);
        }
    }
    bfs(0);
    printf("%d\n", *max_element(d, d + n));
    return 0;
}