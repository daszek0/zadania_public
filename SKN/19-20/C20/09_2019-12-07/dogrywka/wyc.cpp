// Jakub Daszkiewicz
// zadanie Wycinanka

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int d, s, n;
    scanf("%d %d %d", &d, &s, &n);
    int dp[s+1][d+1];
    for (int x=0; x<s+1; x++)
    {
        for (int y=0; y<d+1; y++)
        {
            dp[x][y] = 0;
        }
    }
    int x, y;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &y, &x);
        dp[x][y] = -1;
    }
    int t;
    for (x=1; x<s+1; x++)
    {
        for (y=1; y<d+1; y++)
        {
            if (dp[x][y] != -1)
            {
                t = min(dp[x-1][y-1], min(dp[x-1][y], dp[x][y-1]));
                if (t == -1)
                {
                    dp[x][y] = 1;
                }
                else
                {
                    dp[x][y] = t+1;
                }
            }
        }
    }
    int r = 0;
    for (x=1; x<s+1; x++)
    {
        for (y=1; y<d+1; y++)
        {
            r = max(r, dp[x][y]);
        }
    }
    printf("%d", r*r);
    return 0;
}