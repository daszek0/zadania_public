// Jakub Daszkiewicz
// zadanie Puszki

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 5;// 500;
int c[N + 2][N + 2], dp[N + 2][N + 2];

int main()
{
    int n, K;
    scanf("%d %d", &n, &K);
    // int c[n + 2][n + 2], dp[n + 2][n + 2];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    long long a = 0;
    int s;
    for (int i = 0; i < K; i++)
    {
        for (int j = n; j > 0; j--)
        {
            for (int k = 1; k <= n - j + 1; k++)
            {
                dp[j][k] = dp[j + 1][k - 1] + dp[j + 1][k] + c[j][k] - c[min(j + 2, n + 1)][k - 1];
            }
        }
        s = 1;
        for (int j = 2; j <= n; j++)
        {
            if (dp[1][j] > dp[1][s])
            {
                s = j;
            }
        }
        a += dp[1][s];
        c[1][s] = 0;
        for (int j = 2; j <= n; j++)
        {
            fill(&c[j][max(s - j + 1, 1)], &c[j][s], 0);
        }
    }
    printf("%lld", a);
    return 0;
}