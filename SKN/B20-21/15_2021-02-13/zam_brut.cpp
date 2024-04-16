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
            for (int j = 0; j < m; j++)
            {
                swap(t[a][j], t[b][j]);
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                swap(t[j][a], t[j][b]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            putchar_unlocked(t[i][j]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}