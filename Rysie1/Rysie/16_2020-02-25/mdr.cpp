// Jakub Daszkiewicz
// zadanie Malinowy chruśniak - droga przejścia

#include <stdio.h>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

int main()
{
    int w, k;
    scanf("%d %d", &w, &k);
    int m[w+2][k+2];
    int s[w+2][k+2];
    vector <pair <int, int>> r;
    for (int i=0; i<w+2; i++)
    {
        m[i][0] = 0;
        m[i][k+1] = 0;
        s[i][0] = 0;
        s[i][k+1] = 0;
    }
    for (int i=0; i<k+2; i++)
    {
        m[0][i] = 0;
        m[w+1][i] = 0;
        s[0][i] = 0;
        s[w+1][i] = 0;
    }
    int t;
    for (int y=1; y<w+1; y++)
    {
        for (int x=1; x<k+1; x++)
        {
            scanf("%d", &m[y][x]);
            s[y][x] = max(s[y-1][x], s[y][x-1]) + m[y][x];
        }
    }
    int x = k;
    int y = w;
    while (x > 0 && y > 0)
    {
        r.push_back(make_pair(x, y));
        if (s[y][x-1] == s[y][x] - m[y][x]) x--;
        else y--;
    }
    printf("%d", s[w][k]);
    for (int i=0; i<r.size(); i++)
    {
        printf("\n%d %d", r[i].Y, r[i].X);
    }
    return 0;
}