// Jakub Daszkiewicz
// zadanie Malinowy chruśniak - droga przejścia

// test 1: 5 6 1 2 3 4 5 6 5 4 3 2 1 6 3 4 5 6 7 1 4 5 6 7 8 1 8 9 1 2 3 1 => 44 5 6 5 5 4 5 4 4 4 3 4 2 3 2 2 2 2 1 1 1
// test 2: 4 5 1 2 3 4 5 5 4 3 2 1 3 4 5 6 7 4 5 6 7 8 => 40 4 5 4 4 4 3 4 2 3 2 2 2 2 1 1 1
// test 3: 4 4 1 2 3 4 5 4 3 2 3 4 5 6 4 5 6 7 => 32 4 4 4 3 4 2 3 2 2 2 2 1 1 1

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int t;
    int r[a+2][b+2];
    int s[a+2][b+2];
    vector <int> v[2];
    for (int i=0; i<b+2; i++)
    {
        s[0][i] = 0;
        s[a+1][i] = 0;
        r[0][i] = 0;
        r[a+1][i] = 0;
    }
    for (int i=0; i<a+2; i++)
    {
        s[i][0] = 0;
        s[i][b+1] = 0;
        r[i][0] = 0;
        r[i][b+1] = 0;
    }
    for (int x=1; x<=a; x++)
    {
        for (int y=1; y<=b; y++)
        {
            scanf("%d", &t);
            r[x][y] = t;
            s[x][y] = max(s[x-1][y], s[x][y-1]) + t;
        }
    }
    int x = 1, y = 1;
    // v[0].push_back(x);
    // v[1].push_back(y);
    while (x <= a && y <= b)
    {
        v[0].push_back(x);
        v[1].push_back(y);
        if (s[x+1][y] >= s[x][y+1] && s[x][y] + r[x+1][y] == s[x+1][y]) x++;
        else y++;
    }
    // v[0].push_back(a);
    // v[1].push_back(b);

    printf("%d\n", s[a][b]);
    for (int i=v[0].size()-1; i>=0; i--)
    {
        printf("%d %d\n", v[0][i], v[1][i]);
    }
    return 0;
}