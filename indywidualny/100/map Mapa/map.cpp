// Jakub Daszkiewicz
// zadanie Mapa

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    char r[n][m];
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) r[i][j] = '.';
    int t0, t1;
    for (int i=0; i<k; i++)
    {
        scanf("%d %d", &t0, &t1);
        r[t0 - 1][t1 - 1] = 'X';
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            putchar_unlocked(r[i][j]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}