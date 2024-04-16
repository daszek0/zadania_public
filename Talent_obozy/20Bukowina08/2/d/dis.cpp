// Jakub Daszkiewicz
// zadanie Domy i studnie

#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int s, t;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &s);
        for (int j=0; j<s; j++)
        {
            scanf("%d", &t);
            dp[i][t]++;
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            dp[i][j] = max(dp[i][j] + dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}