// Jakub Daszkiewicz
// zadanie Porządek

#include <stdio.h>

using namespace std;

char g[1000001];
long long m[1000001], rr[1000001], nn[1000001];

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", g + 1);
    for (int i=1; i<=n; i++)
    {
        rr[i] = rr[i - 1];
        nn[i] = nn[i - 1];
        if (g[i] == 'N') nn[i]++;
        if (g[i] == 'R')
        {
            rr[i]++;
            m[i] = m[i - 1];
        }
        else m[i] = m[i - 1] + rr[i];
    }
    int t, a, b;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%lld\n", m[b] - m[a - 1] - (nn[b] - nn[a - 1]) * rr[a - 1]);
    }
    return 0;
}