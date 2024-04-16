// Jakub Daszkiewicz
// zadanie Tanie linie

#include <stdio.h>
#include <algorithm>

using namespace std;

struct maxsum
{
    int f, t, s;
};

bool comp(maxsum a, maxsum b)
{
    if (a.s == b.s) return a.t - a.f > b.t - b.f;
    return a.s < b.s;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int d[n];
    maxsum ms[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }
    int c;
    for (int i = 0; i < n; i++)
    {
        ms[i].f = i;
        ms[i].s = d[i];
        c = d[i];
        for (int j = i + 1; j < n; j++)
        {
            c += d[j];
            if (c > ms[i].s)
            {
                ms[i].s = c;
                ms[i].t = j;
            }
        }
    }
    sort(ms, ms + n, comp);
    for (int i = 0; i < n; i++)
    {
        
    }
    return 0;
}