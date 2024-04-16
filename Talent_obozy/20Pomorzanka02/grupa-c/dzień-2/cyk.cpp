// Jakub Daszkiewicz
// zadanie Czy jest cykl nieparzysty

// test 1: 2 4 6 1 2 1 3 1 4 2 3 2 4 3 4 4 4 1 2 2 3 3 4 4 1 => TAK NIE

#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
vector<int> g[100001];
bool t[100001];
bool v[100001];
bool type = 0;
bool started = 0;

void dfs_type(int x)
{
    v[x] = 1;
    t[x] = type;
    type ^= 1;
    for (int i=0; i<g[x].size(); i++)
    {
        dfs_type(g[x][i]);
    }
}

bool dfs_check(int x, bool last)
{
    if (started) return false;
    started = 1;
    if (t[x] == last) return true;
    else
    {
        for (int i=0; i<g[x].size(); i++)
        {
            if (dfs_check(g[x][i], t[x])) return true;
        }
    }
    return false;
}

int main()
{
    int q, t1, t2;
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
        dfs_type(0);
        for (int i=0; i<100001; i++)
        {
            v[i] = 0;
        }
        if (dfs_check(0, !t[0])) printf("TAK\n");
        else printf("NIE\n");
        for (int i=0; i<100001; i++)
        {
            g[i].clear();
            t[i] = 0;

        }
        started = 0;
        type = 0;
    }
    return 0;
}