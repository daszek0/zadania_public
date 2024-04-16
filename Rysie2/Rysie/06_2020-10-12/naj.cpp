// Jakub Daszkiewicz
// zadanie Najdalsze komnaty

#include <stdio.h>
#include <vector>

using namespace std;

vector <int> g[200001];
bool v[200001];
int fn, md;

void dfs(int n, int d)
{
    d++;
    v[n] = true;
    if (md < d)
    {
        md = d;
        fn = n;
    }
    for (unsigned i=0; i<g[n].size(); i++)
    {
        if (!v[g[n][i]]) dfs(g[n][i], d);
    }
    d--;
}

int main()
{
    int n;
    scanf("%d", &n);
    int t0, t1;
    for (int i=0; i<n-1; i++)
    {
        scanf("%d %d", &t0, &t1);
        g[t0].push_back(t1);
        g[t1].push_back(t0);
    }
    dfs(1, 0);
    fill(v, v+200001, 0);
    md = 0;
    dfs(fn, 0);
    printf("%d", md - 1);
    return 0;
}