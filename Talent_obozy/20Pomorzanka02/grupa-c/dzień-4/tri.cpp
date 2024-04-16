// Jakub Daszkiewicz
// zadanie Trikontenerowiec

// test 1: 10 5 2 1 3 2 5 2 2 10 3 10 => 13

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    unsigned long long r = 0;
    scanf("%d %d", &m, &n);
    int h[m+1];
    for (int i=0; i<m+1; i++)
    {
        h[i] = 0;
    }
    int t1, t2, min_v, min_p;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (t2 <= m)
        {
            min_v = 1000;
            min_p = m;
            for (int j=m; j>=t2; j--)
            {
                if (h[j] <= min_v)
                {
                    min_p = j;
                    min_v = h[j];
                }
            }
            h[min_p] = t1;
        }
    }
    for (int i=0; i<=m; i++)
    {
        r += h[i];
    }
    printf("%llu", r);
    return 0;
}