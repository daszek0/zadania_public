// Jakub Daszkiewicz
// zadanie Maliny

#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 1001;
int w[N][N];

int main()
{
    int m, n, k, ma = 0, pa = 0;
    scanf("%d %d %d", &m, &n, &k);
    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n; j++)
        {
            scanf("%d", &w[i][j]);
            pa += w[i][j];
            w[i][j] += w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
        }
    }
    for (int i=1; i<=m - k + 1; i++)
    {
        for (int j=1; j<=n - k + 1; j++)
        {
            ma = max(ma, w[i + k - 1][j + k - 1] - w[i - 1][j + k - 1] - w[i + k - 1][j - 1] + w[i - 1][j - 1]);
        }
    }
    printf("%d", pa - ma);
    return 0;
}