// Jakub Daszkiewicz
// zadanie Żetony

#include <stdio.h>

using namespace std;

typedef unsigned long long ull;
const ull mod = 1000000007;

ull factorial(ull n)
{
    if (n == 0) return 1;
    return (factorial(n - 1) * n) % mod;
}

int main()
{
    int r, g, b;
    scanf("%d %d %d", &g, &r, &b);
    // ull rf = factorial(r);
    // ull gf = factorial(g);
    // ull bf = factorial(b);
    printf("%llu", ((factorial(r + g + b) / (g * factorial(r + b))) % mod) * ((factorial(r + b) / (factorial(r) * factorial(b))) % mod));
    return 0;
}