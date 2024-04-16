// Jakub Daszkiewicz
// zadanie Panorama Bajhattanu

#include <stdio.h>
#include <algorithm>

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
    int mhx = 0, mhy[m];
    fill(mhy, mhy + m, 0);
    long long a = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            a += min(hx[x], hy[y]);
            mhx = max(mhx, min(hx[x], hy[y]));
            mhy[y] = max(mhy[y], min(hx[x], hy[y]));
        }
        if (mhx != hx[x])
        {
            printf("NIE");
            return 0;
        }
        mhx = 0;
    }
    for (int i = 0; i < m; i++)
        if (hy[i] != mhy[i])
        {
            printf("NIE");
            return 0;
        }
    printf("%lld", a);
    return 0;
}