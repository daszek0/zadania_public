// Jakub Daszkiewicz
// zadanie Żetony

#include <stdio.h>

using namespace std;

const long long mod = 1000000007;

int main()
{
    int g, r, b;
    long long a = 1;
    scanf("%d %d %d", &g, &r, &b);
    for (int i = 0; i < r + b; i++)
    {
        a *= g + 1 + i;
        if (i - r < 0)
            a /= i + 1;
        else
            a /= i - r + 1;
        a %= mod;
    }
    printf("%lld", a);
    return 0;
}