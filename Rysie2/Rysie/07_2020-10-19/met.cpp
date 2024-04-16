// Jakub Daszkiewicz
// zadanie Metro

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct point
{
    int x, y, i;
};

vector <int> g[200001];
int v[200001];

bool point_x(point a, point b)
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool point_y(point a, point b)
{
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

void dfs(int n, int c)
{
    v[n] = c;
    for (int i: g[n])
    {
        if (!v[i]) dfs(i, c);
    }
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    point p[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
        p[i].i = i + 1;
    }
    sort(p, p+n, point_x);
    for (int i=1; i<n; i++)
    {
        if (p[i].x == p[i - 1].x)
        {
            g[p[i].i].push_back(p[i - 1].i);
            g[p[i - 1].i].push_back(p[i].i);
        }
    }
    sort(p, p+n, point_y);
    for (int i=1; i<n; i++)
    {
        if (p[i].y == p[i - 1].y)
        {
            g[p[i].i].push_back(p[i - 1].i);
            g[p[i - 1].i].push_back(p[i].i);
        }
    }
    for (int i=0; i<n; i++)
    {
        if (!v[p[i].i]) dfs(p[i].i, p[i].i);
    }
    int a, b;
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        if (v[a] == v[b]) printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}