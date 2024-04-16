// Jakub Daszkiewicz
// zadanie Zamiany

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, o;
    scanf("%d %d %d", &n, &m, &o);
    getchar_unlocked();
    char t[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            t[i][j] = getchar_unlocked();
        }
        getchar_unlocked();
    }
    int r[n], c[m];
    for (int i = 0; i < n; i++)
    {
        r[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        c[i] = i;
    }
    char ot;
    int a, b;
    for (int i = 0; i < o; i++)
    {
        ot = getchar_unlocked();
        scanf("%d %d", &a, &b);
        getchar_unlocked();
        a--;
        b--;
        if (ot == 'W')
        {
            swap(r[a], r[b]);
        }
        else
        {
            swap(c[a], c[b]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            putchar_unlocked(t[r[i]][c[j]]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}