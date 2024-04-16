// Jakub Daszkiewicz
// zadanie Pole wielokąta

#include <stdio.h>
#include <algorithm>

#define ff first
#define ss second

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    pair <int, int> w[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &w[i].ff, &w[i].ss);
    }
    int r = 0;
    for (int i=0; i<n-1; i++)
    {
        r += w[i].ff * w[i+1].ss - w[i].ss * w[i+1].ff;
    }
    r += w[n-1].ff * w[0].ss - w[n-1].ss * w[0].ff;
    printf("%.2f", (float)abs(r)/2);
    return 0;
}