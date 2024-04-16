// Jakub Daszkiewicz
// zadanie Mapa gęstości

// test 1: 5 1 1 0 0 0 1 1 1 1 0 0 1 0 0 0 0 0 0 0 1 1 0 1 0 0 0 => 3 4 2 2 1
//                                                                  4 5 2 2 1
//                                                                  3 4 3 3 2
//                                                                  2 2 2 2 2
//                                                                  1 1 2 2 2

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, a;
    scanf("%d %d", &n, &a);
    int t[n+1][n+1];
    for (int i=1; i<n+1; i++)
    {
        t[i][0] = 0;
        t[0][i] = 0;
    }
    for (int y=1; y<n+1; y++)
    {
        for (int x=1; x<n+1; x++)
        {
            scanf("%d", &t[x][y]);
        }
    }
    int s[n+1][n+1];
    for (int i=1; i<n+1; i++)
    {
        s[i][0] = 0;
        s[0][i] = 0;
    }
    for (int y=1; y<n+1; y++)
    {
        for (int x=1; x<n+1; x++)
        {
            s[x][y] = s[x-1][y] + s[x][y-1] - s[x-1][y-1] + t[x][y];
        }
    }
    for (int y=1; y<n+1; y++)
    {
        for (int x=1; x<n+1; x++)
        {
            printf("%d ", s[x + min(a, n-x)][y + min(a, n-y)] - s[x - min(a, x-1) - 1][y + min(a, n-y)] - s[x + min(a, n-x)][y - min(a, y-1) - 1] + s[x - min(a, x-1) - 1][y - min(a, y-1) - 1]);
        }
        printf("\n");
    }
    return 0;
}