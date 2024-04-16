// Jakub Daszkiewicz
// zadanie Ciąg k-parzysty

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    unsigned long long t;
    scanf("%d %d", &n, &k);
    bool s[n];
    for (int i=0; i<n; i++)
    {
        scanf("%llu", &t);
        s[i] = t % 2;
    }
    int c = 0, c0 = 0, c1 = 0, r = 0, md = 1000001;
    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < n; j += k)
        {
            if (s[j] == 0) c0++;
            else c1++;
        }
        r += min(c0, c1);
        if (c0 < c1) c++;
        md = min(md, abs(c0-c1));
        c0 = 0;
        c1 = 0;
    }
    if (c % 2 == 1) r += md;
    printf("%d", r);
    return 0;
}