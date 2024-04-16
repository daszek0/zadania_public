// Jakub Daszkiewicz
// zadanie Rating

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    unsigned long long t, p;
    scanf("%llu", &p);
    int rt = 1, r = 1;
    for (int i=1; i<n; i++)
    {
        scanf("%llu", &t);
        if (t > p)
        {
            rt++;
            r = max(rt, r);
        }
        else rt = 1;
        p = t;
    }
    printf("%d", r);
    return 0;
}