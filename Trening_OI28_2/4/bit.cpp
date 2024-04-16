// Jakub Daszkiewicz
// zadanie Bitmapa

#include <cstdio>
#include <iostream>
// #include <algorithm>

using namespace std;

const int inf = 1 << 30;

int main()
{
    int n, m;
    // scanf("%d %d\n", &n, &m);
    cin >> n >> m;
    bool b[n][m];
    int f[n][m];
    // fill(&f[0][0], &f[n][m], inf);
    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // c = getchar_unlocked();
            cin >> c;
            b[i][j] = c - '0';
            if (b[i][j] == 1)
            {
                f[i][j] = 0;
            }
            else
            {
                f[i][j] = inf;
            }
        }
        // getchar_unlocked();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (f[i][j + 1] > f[i][j] + 1)
            {
                f[i][j + 1] = f[i][j] + 1;
            }
        }
        for (int j = n - 1; j > 0; j--)
        {
            if (f[i][j - 1] > f[i][j] + 1)
            {
                f[i][j - 1] = f[i][j] + 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (f[j + 1][i] > f[j][i] + 1)
            {
                f[j + 1][i] = f[j][i] + 1;
            }
        }
        for (int j = n - 1; j > 0; j--)
        {   
            if (f[j - 1][i] > f[j][i] + 1)
            {
                f[j - 1][i] = f[j][i] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            // printf("%d ", f[i][j]);
            cout << f[i][j] << ' ';
        }
        // printf("\n");
        cout << f[i][m - 1] << '\n';
    }
    return 0;
}