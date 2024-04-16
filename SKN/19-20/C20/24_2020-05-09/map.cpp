// Jakub Daszkiewicz
// zadanie Mapa

#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int n, m, k, x, y;
    scanf("%d %d %d", &n, &m, &k);
    char output[n][m];
    memset(output, '.', n*m);
    for (int i=0; i<k; i++)
    {
        scanf("%d %d", &y, &x);
        output[y-1][x-1] = 'X';
    }
    for (y=0; y<n; y++)
    {
        for (x=0; x<m; x++)
        {
            putchar_unlocked(output[y][x]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}