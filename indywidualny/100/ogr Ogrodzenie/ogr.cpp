// Jakub Daszkiewicz
// zadanie Ogrodzenie

#include <stdio.h>
#include <algorithm>

#define x first
#define y second

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    pair <int, int> p[n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    p[n] = p[0];
    int gcd, xo, yo, xp, yp;
    for (int i = 1; i <= n; i++)
    {
        gcd = __gcd(abs(p[i].x - p[i - 1].x), abs(p[i].y - p[i - 1].y));
        xo = (p[i].x - p[i - 1].x) / gcd;
        yo = (p[i].y - p[i - 1].y) / gcd;
        xp = p[i - 1].x;
        yp = p[i - 1].y;
        while (xp != p[i].x || yp != p[i].y)
        {
            printf("%d %d\n", xp, yp);
            xp += xo;
            yp += yo;
        }
    }
    return 0;
}