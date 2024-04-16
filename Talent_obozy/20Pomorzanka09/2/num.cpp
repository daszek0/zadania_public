// Jakub Daszkiewicz
// zadanie Numerowanie

#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 100000007; // modulo
vector <int> g[200001]; // graf
bool v[2000001]; // tablica odwiedzonych

ll dfs(int n, int f)
{
    ll ret = 1; // wartość do zwrócenia
    v[n] = true;
    if (g[n].size() == 1 && f != 0) return 0;
    ll sr = 0; // wynik syna
    for (unsigned i=0; i<g[n].size(); i++)
    {
        if (!v[g[n][i]])
        {
            sr += dfs(g[n][i], n);
            
        }
    }
    for (unsigned j= ((f == 0) ? 0 : 2); j<g[n].size(); j++)
    {
        ret *= (j + sr) % mod;
    }
    return ret % mod;
}

int main()
{
    int n; // liczba wierzchołków
    scanf("%d", &n);
    int t0, t1; // zmienne pomocnicze
    for (int i=0; i<n-1; i++)
    {
        scanf("%d %d", &t0, &t1);
        g[t0].push_back(t1);
        g[t1].push_back(t0);
    }
    for (int i=1; i<=n; i++) // numer wiersza i wierzchołek wywołania
    {
        printf("%lld\n", dfs(i, 0));
        fill(v, v+2000001, false);
    }
    return 0;
}