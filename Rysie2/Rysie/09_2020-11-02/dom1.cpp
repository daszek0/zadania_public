// Jakub Daszkiewicz
// zadanie Dominujące liczby

#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long a[n];
    for (int i=0; i<n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a, a+n);
    set <long long> s;
    s.insert(a, a+n);
    long long c, c2, c3;
    for (int i=0; i<n; i++)
    {
        c = a[i];
        c2 = c * c;
        c3 = c2 * c;
        if (s.count(c) > 0 && s.count(c2) > 0 && s.count(c3) > 0)
        {
            printf("%lld", c);
            return 0;
        }
    }
    printf("NIE");
    return 0;
}