// Jakub Daszkiewicz
// zadanie Wina [B]
//
// test 1: 5 7 1999 2019 2010 850 1500 1600 900 900 710 900 1000 800 600 800 1000 => 710

#include <stdio.h>

using namespace std;

int main()
{
    int n, k, t, r = 2147483647;
    scanf("%d %d", &n, &k);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            scanf("%d", &t);
            if (t < r && j*(i-j+1) <= k) r = t;
        }
    }
    printf("%d", r);
    return 0;
}