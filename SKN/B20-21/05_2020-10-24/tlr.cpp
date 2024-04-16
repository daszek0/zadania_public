// Jakub Daszkiewicz
// zadanie Talerz ciastek

#include <stdio.h>
#include <algorithm>

using namespace std;

int ch[1002][1002], cv[1002][1002];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char p[n + 2][m + 2];
    fill(&p[0][0], &p[0][0] + sizeof(p), '.');
    for (int i = 1; i <= n; i++)
    {
        getchar_unlocked();
        for (int j = 1; j <= m; j++)
        {
            p[i][j] = getchar_unlocked();
        }
    }
    // int ch[n + 2][m + 2], cv[n + 2][m + 2];
    // fill(&ch[0][0], &ch[0][0] + sizeof(ch), 0);
    // fill(&cv[0][0], &cv[0][0] + sizeof(cv), 0);
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            if (p[i][j] == '#') c++;
            else
            {
                ch[i][j] = c;
                c = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            if (p[j][i] == '#') c++;
            else
            {
                cv[j][i] = c;
                c = 0;
            }
        }
    }
    int a = __INT_MAX__;
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < m + 2; j++)
        {
            a = min(a, min(ch[i][j] > 0 ? ch[i][j] : __INT_MAX__, cv[i][j] > 0 ? cv[i][j] : __INT_MAX__));
        }
    }
    printf("%d", a);
    return 0;
}