#include <stdio.h>

using namespace std;

int main()
{
    unsigned long long n, m, r = 0;
    scanf("%llu %llu", &n, &m);
    while (n > 0 && m > 0)
    {
        if (n > m)
        {
            n -= m;
            r++;
        }
        else
        {
            m -= n;
            r++;
        }
    }
    printf("%llu", r);
    return 0;
}
