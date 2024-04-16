// Jakub Daszkiewicz
// zadanie Księgozbiór

#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k, t, ac[2], ap[2], tc[2], tp[2];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        ac[0] = min(ap[0] + max(t % k - tp[0] % k, 0), ap[1] + max(t % k - tp[1] % k, 0));
        tc[0] = t % k;
        ac[1] = min(ap[0] + max(t % k + k - tp[0] % k, 0), ap[1] + max(t % k + k - tp[1] % k, 0));
        tc[1] = t % k + k;
        swap_ranges(ac, ac + 2, ap);
        swap_ranges(tc, tc + 2, tp);
    }
    printf("%d", min(ap[0], ap[1]));
    return 0;
}