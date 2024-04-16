// Jakub Daszkiewicz
// zadanie Miś na liczbach

// brut na pałę

#include <stdio.h>

using namespace std;

long long pow2n(long long n)
{
    if (n > 1)
    {
        long long r = 1;
        for (long long i=0; i<n; i++)
        {
            r <<= 1;
        }
        return r;
    }
    else return 2;
}

long long pow22n(/* long long a,  */long long n, long long m)
{
    if (n > 0)
    {
        long long r = 1;// pow2n(n - 1, m) % m;
        for (long long i=0; i<pow2n(n); i++)
        {
            r <<= 1;
            r %= m;
        }
        return r;
    }
    else return 2;
}

int main()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld", pow22n(n , m));
    return 0;
}