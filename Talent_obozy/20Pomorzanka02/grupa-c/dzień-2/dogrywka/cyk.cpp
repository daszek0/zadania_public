// Jakub Daszkiewicz
// zadanie Czy jest cykl nieparzysty

// test 1: 2 4 6 1 2 1 3 1 4 2 3 2 4 3 4 4 4 1 2 2 3 3 4 4 1 => TAK NIE

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> g[100001];
bool v[100001];
bool c[100001];
bool r = 0;

void dfs(int x)
{
    v[x] = 1;
    for (int i=0; i<g[x].size(); i++)
    {
        if (!v[g[x][i]])
        {
            c[g[x][i]] = !c[x];
            dfs(g[x][i]);
        }
        else
        {
            if (c[g[x][i]] == c[x])
            {
                r = 1;
                return;
            }
        }
    }
}

int main()
{
    int q, n, m, t1, t2;
    scanf("%d", &q);
    for (int p=0; p<q; p++)
    {
        scanf("%d %d", &n, &m);
        for (int i=0; i<m; i++)
        {
            scanf("%d %d", &t1, &t2);
            g[t1-1].push_back(t2-1);
            g[t2-1].push_back(t1-1);
        }
        c[0] = 0;
        dfs(0);
        if (!r)
        {
            for (int i=1; i<n; i++)
            {
                if (!v[i]) dfs(i);
            }
        }
        if (r) printf("TAK\n");
        else printf("NIE\n");
        for (int i=0; i<100001; i++)
        {
            g[i].clear();
            v[i] = 0;
            c[i] = 0;
            r = 0;
        }
    }
    return 0;
}