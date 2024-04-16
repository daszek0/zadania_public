// Jakub Daszkiewicz
// zadanie Działka

#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[2001][2001], m[2001][2001];

bool check(int h, int g, int i, int j/* pair <int, int> ul, pair <int, int> lr */)
{
    if (dp[i][j] - dp[h - 1][j] - dp[i][g - 1] + dp[h - 1][g - 1] > 0) return true;
    // if (dp[lr.first][lr.second] - dp[ul.first - 1][lr.second] - dp[lr.first][ul.second - 1] > 0) return true;
    return false;
}

int main()
{
    int n, r = 0;
    scanf("%d", &n);
    // int m[n+1][n+1]/* , dp[n+1][n+1] */;
    // for (int i=0; i<=n; i++) for (int j=0; j<=n; j++)
    // {
    //     m[i][j] = 0;
    //     // dp[i][j] = 0;
    // }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            scanf("%d", &m[i][j]);
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + m[i][j];
        }
    }
    for (int g=1; g<=n; g++)
    {
        for (int h=1; h<=n; h++)
        {
            if (m[h][g] == 1) continue;
            for (int i=h; i<=n; i++)
            {
                if (m[i][g] == 1) continue;
                for (int j=g; j<=n; j++)
                {
                    // if ((j-g+1)*(i-h+1) == 12)
                    // {
                    //     printf("xD\n");
                    //     printf("lewy górny %d %d\n", h, g);
                    //     printf("prawy dolny %d %d\n", i, j);
                    // }
                    if (!check(h, g, i, j/* make_pair(h, g), make_pair(i, j) */)) r = max(r, (j-g+1)*(i-h+1));
                    else break;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}