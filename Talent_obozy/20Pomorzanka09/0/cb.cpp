// Jakub Daszkiewicz
// zadanie Ciąg Bajtazara

// cock and ball

#include <stdio.h>

using namespace std;

typedef long long ll;

const ll m = 1000213769;

ll cbt(ll n)
{
    if (n == 0) return 7;
    ll l1 = cbt(n - 1) % m;
    return (l1 * l1 + 1) % m;
}

int main()
{
    ll n;
    scanf("%lld", &n);
    printf("%lld", cbt(n));
    return 0;
}