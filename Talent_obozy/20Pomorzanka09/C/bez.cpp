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

vector <int> g[200000];
int d[200000];

void bfs(int n)
{
    queue <pair <int, int>> q;
    int v[200000];
    fill(v, v+200000, 0);
    q.push(mp(n, 0));
    pair <int, int> cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.ss > d[cur.ff]) continue;
        d[cur.ff] = min(d[cur.ff], cur.ss);
        v[cur.ff] = 1;
        for (auto i: g[cur.ff])
        {
            if (!v[i]) q.push(mp(i, cur.ss + 1));
        }
    }
}

int main()
{
    fill(d, d+200000, 21372137);
    int n;
    scanf("%d", &n);
    int t0, t1;
    for (int i=0; i<n-1; i++)
    {
        scanf("%d %d", &t0, &t1);
        t0--;
        t1--;
        g[t0].push_back(t1);
        g[t1].push_back(t0);
    }
    for (int i=0; i<n; i++)
    {
        if (g[i].size() == 1)
        {
            bfs(i);
        }
    }
    printf("%d", *max_element(d, d + n));
    return 0;
}