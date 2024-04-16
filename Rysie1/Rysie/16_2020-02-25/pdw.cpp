// Jakub Daszkiewicz
// zadanie Pole wielokąta

#include <stdio.h>
#include <algorithm>

#define x first
#define y second

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    pair <int, int> p[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    int r = 0;
    for (int i=1; i<n; i++)
    {
        r += p[i-1].x*p[i].y - p[i].x*p[i-1].y;
    }
    r += p[n-1].x*p[0].y - p[0].x*p[n-1].y;
    r = abs(r);
    printf("%.2f", (float)r/2);
    return 0;
}