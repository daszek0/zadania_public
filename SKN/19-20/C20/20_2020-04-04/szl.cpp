// Jakub Daszkiewicz
// zadanie Szlaki turystyczne

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int r[n], t, res = 0;
    fill(r, r+n, 0);
    for (int i=0; i<2*n-2; i++)
    {
        scanf("%d", &t);
        r[t-1]++;
    }
    for (int i=0; i<n; i++)
    {
        res = max(res, r[i]);
    }
    printf("%d", res);
    return 0;
}