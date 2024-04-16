// Jakub Daszkiewicz
// zadanie Malinowy chruśniak - droga przejścia

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int w, k;
    scanf("%d %d", &w, &k);
    int s[k+2][w+2], m[k+2][w+2];
    vector <pair <int, int>> r;
    for (int i=0; i<k+2; i++)
    {
        s[i][0] = 0;
        s[i][w+1] = 0;
        m[i][0] = 0;
        m[i][w+1] = 0;
    }
    for (int i=0; i<w+2; i++)
    {
        s[0][i] = 0;
        s[k+1][i] = 0;
        m[0][i] = 0;
        m[k+1][i] = 0;
    }
    for (int y=1; y<w+1; y++)
    {
        for (int x=1; x<k+1; x++)
        {
            scanf("%d", &m[x][y]);
            s[x][y] = max(s[x-1][y], s[x][y-1]) + m[x][y];
        }
    }
    int x = k, y = w;
    while (x > 0 && y > 0)
    {
        r.push_back(make_pair(x, y));
        if (s[x-1][y] == s[x][y] - m[x][y]) x--;
        else y--;
    }
    printf("%d", s[k][w]);
    for (int i=0; i<r.size(); i++)
    {
        printf("\n%d %d", r[i].second, r[i].first);
    }
    return 0;
}