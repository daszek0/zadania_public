// Jakub Daszkiewicz
// zadanie Zwrotnice

#include <stdio.h>
#include <vector>

using namespace std;

int g[100000][2];
vector <int> tc[100000];
int s, e;
bool v[100000];

int dijkstra()
{
    for (int i=0; i<100000; i++)
    {
        for (int j=0; j<tc[i].size(); j++)
        {
            if (v[tc[i][j]]) continue;
            v[tc[i][j]] = 1;
            if (tc[i][j] == e) return i;
            tc[i+0].push_back(g[tc[i][j]][0]);
            tc[i+1].push_back(g[tc[i][j]][1]);
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d %d %d", &n, &s, &e);
    s--;
    e--;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &g[i][0], &g[i][1]);
        g[i][0]--;
        g[i][1]--;
    }
    tc[0].push_back(g[s][0]);
    tc[1].push_back(g[s][1]);
    v[s] = 1;
    int r = dijkstra();
    if (r == -1) printf("BRAK");
    else printf("%d", r);
    return 0;
}