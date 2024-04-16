// Jakub Daszkiewicz
// zadanie Duplikacja

#include <stdio.h>
#include <vector>

using namespace std;

const long long mod = 1000696969;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    long long a[n];
    for (int i=0; i<n; i++)
    {
        scanf("%lld", &a[i]);
    }
    vector <int> g[n];
    int u, v;
    for (int i=0; i<m; i++)
    {
        scanf("%d %d", &u, &v);
        g[min(u, v) - 1].push_back(max(u, v) - 1);
    }
    for (int i=0; i<n; i++)
    {
        for (auto d: g[i])
        {
            a[d] += a[i];
            a[d] %= mod;
        }
    }
    for (int i=0; i<n; i++)
    {
        printf("%lld ", a[i]);
    }
    return 0;
}