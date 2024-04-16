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
    int n, r;
    scanf("%d %d", &n, &r);
    int s[n+1][n+1];
    for (int i=0; i<n+1; i++)
    {
        s[0][i] = 0;
        s[i][0] = 0;
    }
    int t;
    for (int y=1; y<n+1; y++)
    {
        for (int x=1; x<n+1; x++)
        {
            scanf("%d", &t);
            s[x][y] = s[x-1][y] + s[x][y-1] - s[x-1][y-1] + t;
        }
    }
    for (int y=1; y<n+1; y++)
    {
        for (int x=1; x<n+1; x++)
        {
            printf("%d ", s[min(x+r, n)][min(y+r, n)] - s[min(x+r, n)][max(y-r, 1)-1] - s[max(x-r, 1)-1][min(y+r, n)] + s[max(x-r, 1)-1][max(y-r, 1)-1]);
        }
        printf("\n");
    }
    return 0;
}