// Jakub Daszkiewicz
// zadanie Truskawkowe żniwa

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int w, k;
    scanf("%d %d", &w, &k);
    int s[k+1][w+1];
    int t;
    for (int i=0; i<w+1; i++)
    {
        s[0][i] = 0;
    }
    for (int i=0; i<k+1; i++)
    {
        s[i][0] = 0;
    }
    for (int y=1; y<=w; y++)
    {
        for (int x=1; x<=k; x++)
        {
            scanf("%d", &t);
            s[x][y] = max(s[x-1][y], s[x][y-1]) + t;
        }
    }
    printf("%d", s[k][w]);
    return 0;
}