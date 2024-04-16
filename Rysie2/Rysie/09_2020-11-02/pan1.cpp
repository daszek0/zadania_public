// Jakub Daszkiewicz
// zadanie Panorama Bajhattanu

#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int hx[n], hy[m];
    for (int i = 0; i < n; i++)
        scanf("%d", &hx[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &hy[i]);
    sort(hx, hx + n, greater<int>());
    sort(hy, hy + m, greater<int>());
    if (hx[0] != hy[0])
    {
        printf("NIE");
        return 0;
    }
    long long sy[m + 1];
    sy[m - 1] = hy[m - 1];
    sy[m] = 0;
    for (int i = m - 2; i >= 0; i--)
    {
        sy[i] = hy[i] + sy[i + 1];
    }
    int y = 0;
    long long a = 0;
    for (int x = 0; x < n; x++)
    {
        while (hx[x] < hy[y] && y < m) y++;
        a += (long long)y * (long long)hx[x];
        a += sy[y];
    }
    printf("%lld", a);
    return 0;
}