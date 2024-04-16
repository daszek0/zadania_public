// Jakub Daszkiewicz
// zadanie Zjeżdżalnie

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int r[n], c[m];
    fill(r, r + n, -__INT_MAX__ - 1);
    fill(c, c + m, -__INT_MAX__ - 1);
    r[0] = 1;
    c[0] = 1;
    int h, s, f;
    pair<int, int> p[n * m + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &h);
            if (i == 0 && j == 0)
                s = h;
            if (i == n - 1 && j == m - 1)
                f = h;
            p[h] = make_pair(i, j);
        }
    }
    h = -__INT_MAX__ - 1;
    for (int i = s; i >= f; i--)
    {
        h = max(r[p[i].first], c[p[i].second]);
        r[p[i].first] = h + 1;
        c[p[i].second] = h + 1;
    }
    if (h < 1)
        printf("-1");
    else
        printf("%d", h);
    return 0;
}