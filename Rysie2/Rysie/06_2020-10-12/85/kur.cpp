// Jakub Daszkiewicz
// zadanie Kurort narciarski

#include <stdio.h>
#include <vector>
#include <algorithm>

#define ff first
#define ss second

using namespace std;

vector <pair <int, int>> g[1002];
int v[1002][2002];

void dfs(int n, int p)
{
    v[n][p] = 1;
    for (int i=0; i<g[n].size(); i++)
    {
        if (p - g[n][i].ss > 0 && !v[g[n][i].ff][p - g[n][i].ss]) dfs(g[n][i].ff, p - g[n][i].ss);
    }
}

int main()
{
    int n, n_;
    scanf("%d %d", &n, &n_);
    int k;
    scanf("%d", &k);
    int p, q, r;
    for (int i=0; i<k; i++)
    {
        scanf("%d %d", &p, &q);
        g[p].push_back(make_pair(q, 0));
    }
    int m;
    scanf("%d", &m);
    for (int i=0; i<m; i++)
    {
        scanf("%d %d %d", &p, &q, &r);
        g[p].push_back(make_pair(q, r));
    }
    int b, s;
    scanf("%d %d", &b, &s);
    dfs(b, s);
    int a = __INT_MAX__;
    for (int i=1; i<=n_; i++)
    {
        for (int j=0; j<=s; j++)
        {
            if (v[i][j]) a = min(a, j);
        }
    }
    printf("%d", a);
    return 0;
}