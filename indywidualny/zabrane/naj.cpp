// Jakub Daszkiewicz
// zadanie Najdłuższe ścieżki

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector <int> g[500001];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue <int> q; // bfs
    for (int i=1; i<=n; i++)
    {
        if (g[i].size() == 1) q.push(i);
    }

    return 0;
}