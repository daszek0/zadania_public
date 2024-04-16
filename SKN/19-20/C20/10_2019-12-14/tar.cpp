// Jakub Daszkiewicz
// zadanie Tarasy
//
// test 1: 5 1 4 2 1 2 4 => 4

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, ks, ke, rs = 1, re = 1;
    scanf("%d%d", &n, &ks);
    ke = ks;
    int h[n];
    for (int i=0; i<n; i++)
        scanf("%d", &h[i]);
    for (int i=1; i<n; i++)
    {
        if (h[i] <= h[i-1]) rs++;
        else
        {
            if (ks-(h[i]-h[i-1]) >= 0)
            {
                rs++;
                ks -= (h[i]+h[i-1]);
            }
            else break;
        }
    }
    for (int i=n-1; i>0; i--)
    {
        if (h[i-1] <= h[i]) re++;
        else
        {
            if (ke-(h[i-1]-h[i]) >= 0)
            {
                re++;
                ke -= (h[i-1]+h[i]);
            }
            else break;
        }
    }
    printf("%d", max(rs, re));
    return 0;
}