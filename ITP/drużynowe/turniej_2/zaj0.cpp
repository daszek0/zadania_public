// Wild Algorithm Rangers
// zadanie Zajęcia

#include <stdio.h>
#include <vector>

#define ull unsigned long long

using namespace std;

vector <ull> s;

ull x(ull c[], ull t[], ull r[], ull n, ull I)
{
    ull m = 0;
    s.clear();
    for (int i=0; i<I; i++)
    {
        if (t[i] <= t[I]/2)
        {
            s.push_back(r[i]);
        }
    }
    for (int i=0; i<s.size(); i++)
    {
        if (s[i] > m) m = s[i];
    }
    return m;
}

ull a_max(ull a[], ull l)
{
    ull m = 0;
    for (int i=0; i<l; i++)
    {
        if (a[i] > m) m = a[i];
    }
    return m;
}

int main()
{
    ull n;
    scanf("%llu", &n);
    ull c[n], t[n], r[n];
    for (int i=0; i<n; i++)
    {
        scanf("%llu %llu", &c[i], &t[i]);
        r[i] = c[i] + x(c, t, r, n, i);
    }
    printf("%llu", a_max(r, n));
    return 0;
}