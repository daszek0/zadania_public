// Jakub Daszkiewicz
// zadanie Tapczany

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct sofa
{
    unsigned long long p;
    unsigned long long s;
    unsigned n;
};

bool comp(sofa s0, sofa s1)
{
    if (s0.p == s1.p) return (s0.s > s1.s);
    return (s0.p < s1.p);
}

int main()
{
    unsigned n;
    scanf("%u", &n);
    sofa s[n];
    for (unsigned i=0; i<n; i++)
    {
        scanf("%llu %llu", &s[i].p, &s[i].s);
        s[i].n = i;
    }
    sort(s, s+n, comp);
    unsigned long long ms = s[0].s;
    vector <unsigned> r;
    for (unsigned i=1; i<n; i++)
    {
        if (s[i].s <= ms)
        {
            r.push_back(s[i].n);
        }
        ms = max(ms, s[i].s);
    }
    sort(r.begin(), r.end());
    printf("%u\n", r.size());
    for (unsigned i=0; i<r.size(); i++)
    {
        printf("%u ", r[i] + 1);
    }
    putchar_unlocked('\n');
    return 0;
}