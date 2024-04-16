// Jakub Daszkiewicz
// zadanie Pole

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int x1[2], y1[2], x2[2], y2[2];
    scanf("%d%d%d%d", &x1[0], &y1[1], &x1[1], &y1[0]);
    scanf("%d%d%d%d", &x2[0], &y2[1], &x2[1], &y2[0]);
    long long x, y;
    x = min(x1[1], x2[1])-max(x1[0], x2[0]);
    y = min(y1[1], y2[1])-max(y1[0], y2[0]);
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    printf("%lld", x*y);
    return 0;
}