// Jakub Daszkiewicz
// zadanie Domino

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long s = 0, ab, t0, t1, fgc = 0, av;
    vector <int> a;
    vector <bool> fg;
    for (int i=0; i<n; i++)
    {
        scanf("%lld %lld", &t0, &t1);
        ab = abs(t0 - t1);
        if (ab == 0) continue;
        s += ab;
        a.push_back(2*ab);
        fg.push_back(t0 > t1);
        if (fg.back()) fgc++;
    }
    long long b[(s << 1)+1];
    fill(b, b+(s << 1)+1, (1 << 20));
    b[0] = fgc;
    av = (1 << 20);
    for (int i=0; i<a.size(); i++)
    {
        for (int j=(s << 1); j>=0; j--)
        {
            if (b[j] == (1 << 20)) continue;
            b[j+a[i]] = min(b[j+a[i]], b[j] + (fg[i] ? -1 : 1));
        }
    }
    bool f=0;
    for (int i=0; i<=s && !f; i++)
    {
        if (b[s+i] != (1 << 20))
        {
            av = min(av, b[s+i]);
            f = true;
        }
        if (b[s-i] != (1 << 20))
        {
            av = min(av, b[s-i]);
            f = true;
        }
    }
    printf("%lld", av);
    return 0;
}