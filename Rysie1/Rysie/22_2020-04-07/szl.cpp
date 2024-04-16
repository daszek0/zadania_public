// Jakub Daszkiewicz
// zadanie Szlaki turystyczne

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, t;
    scanf("%d", &n);
    int c[n];
    fill(c, c+n, 0);
    for (int i=0; i<2*n-2; i++)
    {
        scanf("%d", &t);
        c[t-1]++;
    }
    int r = 1;
    for (int i=0; i<n; i++)
    {
        r = max(r, c[i]);
    }
    printf("%d", r);
    return 0;
}