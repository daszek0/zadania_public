// Jakub Daszkiewicz
// zadanie Dziewczynki

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, t, r = 1000000;
    vector <int> g;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if (t == 0) g.push_back(i);
    }
    if (g.size() > 0 && g.size() >= k)
    {
        for (int i = 0 ; i < g.size() - k + 1; i++)
        {
            r = min(r, g[i + k - 1] - g[i] - k + 1);
        }
    }
    if (r == 1000000) printf("NIE");
    else printf("%d", r);
    return 0;
}