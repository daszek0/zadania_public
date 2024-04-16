// Jakub Daszkiewicz
// zadanie Jedzenie

#include <cstdio>

using namespace std;

long long dp[334][1001];
const int mod = 1000000009;

int main()
{
    int n, k;
    long long a = 0;
    scanf("%d %d", &n, &k);
    n /= 3;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * (long long)(j + 1);
            dp[i][j] %= mod;
        }
    }
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; i + j <= k; j++)
        {
            a += (((dp[n][i] * dp[n][j]) % mod) * dp[n][k - i - j]) % mod;
            // a %= mod;
            if (a >= mod)
                a -= mod;
        }
    }
    printf("%lld", a);
    return 0;
}