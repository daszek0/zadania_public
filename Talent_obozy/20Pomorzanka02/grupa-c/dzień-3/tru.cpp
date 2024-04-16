// Jakub Daszkiewicz
// zadanie Truskawkowe żniwa

// test 1: 5 6 1 2 3 4 5 6 5 4 3 2 1 6 3 4 5 6 7 1 4 5 6 7 8 1 8 9 1 2 3 1 => 44
// test 2: 4 5 1 2 3 4 5 5 4 3 2 1 3 4 5 6 7 4 5 6 7 8 => 40
// test 3: 4 4 1 2 3 4 5 4 3 2 3 4 5 6 4 5 6 7 => 32

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int r, c, t;
    scanf("%d %d", &r, &c);
    int s[c+1][r+1];
    for (int i=0; i<c+1; i++)
    {
        s[i][0] = 0;
    }
    for (int i=0; i<r+1; i++)
    {
        s[0][i] = 0;
    }
    for (int y=1; y<r+1; y++)
    {
        for (int x=1; x<c+1; x++)
        {
            scanf("%d", &t);
            s[x][y] = max(s[x-1][y], s[x][y-1]) + t;
        }
    }
    printf("%d", s[c][r]);
    return 0;
}