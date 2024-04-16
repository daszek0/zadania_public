// Jakub Daszkiewicz
// zadanie Liczba zbiorów n-k-specjalnych

#include <stdio.h>

using namespace std;

int dp[101][402][2];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;
    for (int i=2; i<=100; i++)
    {
        for (int j=0; j<=400; j++)
        {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] += dp[i - 1][j - i][0] + dp[i - 1][j - i][1];
        }

    }
    printf("%d", dp[n][k][1]);
    return 0;
}