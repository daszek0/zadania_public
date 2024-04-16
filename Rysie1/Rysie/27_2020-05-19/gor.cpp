// Jakub Daszkiewicz
// zadanie Góry

#include <stdio.h>
#include <vector>

using namespace std;

vector <int> graph[1000001];
int h[1000001];
bool v[1000001];
int start, finish;
long long r;
bool kszykszy = true;

void dfs(int c)
{
    v[c] = 1;
    if (c == finish) kszykszy = false;
    r += h[c];
    for (int i=0; i<graph[c].size(); i++)
    {
        if (!v[graph[c][i]]) dfs(graph[c][i]);
    }
}

int main()
{
    int m, p, t0, t1;
    scanf("%d %d %d %d", &m, &p, &start, &finish);
    for (int i=1; i<=m; i++)
    {
        scanf("%d", &h[i]);
    }
    for (int i=0; i<p; i++)
    {
        scanf("%d %d", &t0, &t1);
        graph[t0].push_back(t1);
        graph[t1].push_back(t0);
    }
    dfs(start);
    if (kszykszy) printf("KSZYKSZY");
    else printf("%lld", r);
    return 0;
}