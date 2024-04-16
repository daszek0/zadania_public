// Jakub Daszkiewicz
// zadanie Mała pamięć

#include <stdio.h>

using namespace std;

typedef long long ll;

const int mod = 694202137;

int main()
{
    char c;
    scanf("%d\n"); // c = getchar_unlocked();
    // while (c <= 'a' || c >= 'z') c = getchar_unlocked();
    ll f = 0, b = 0, p = 37;
    c = getchar_unlocked();
    while (c >= 'a' && c <= 'z')
    {
        f += (ll(c - 'a') * p) % mod;
        f %= mod;
        p *= 37;
        p %= mod;
        b *= 37;
        b %= mod;
        b += (ll(c - 'a') * 37) % mod;
        c = getchar_unlocked();
    }
    if (f == b) printf("TAK\n");
    else printf("NIE\n");
    return 0;
}