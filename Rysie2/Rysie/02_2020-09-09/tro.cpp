// Jakub Daszkiewicz
// zadanie Trójkąt

#include <stdio.h>
#include <algorithm>

using namespace std;

int t[101][101], dp[102][102];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<i+1; j++)
        {
            scanf("%d", &t[i][j]);
        }
    }
    for (int i=n; i>=0; i--)
    {
        for (int j=0; j<i+1; j++)
        {
            dp[i][j] = t[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    printf("%d", dp[0][0]);
    return 0;
}