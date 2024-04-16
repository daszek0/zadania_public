#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n, m, r = 0;
    scanf("%llu %llu", &n, &m);
    if (n != m)
        r = 1;
    do
    {
        if (n > m)
        {
            n -= m;
        }
        else if (m > n)
        {
            m -= n;
        }
        r++;
    } while (n != m);

    printf("%llu", r);
    return 0;
}
