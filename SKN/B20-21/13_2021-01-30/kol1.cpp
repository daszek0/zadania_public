// Jakub Daszkiewicz
// zadanie Kolorowanie

#include <cstdio>
#include <algorithm>

using namespace std;

int it[2][100], t[100], v[100];

void dfs(int n, int f)
{
    v[n] = 1;
    if (t[n] != f)
        dfs(t[n], f);
}

int main()
{
    long long a = 1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &it[i][j]);
            it[i][j]--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (it[1][i] < it[0][i])
            swap(it[1][i], it[0][i]);
        if (t[it[0][i]] == 0)
        {
            t[it[0][i]] = it[1][i];
        }
        else
        {
            t[it[1][i]] = it[0][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            a <<= 1;
            dfs(i, i);
        }
    }
    printf("%lld", a);
    return 0;
}