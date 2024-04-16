// Jakub Daszkiewicz
// zadanie Klocki

#include <stdio.h>
#include <algorithm>

using namespace std;

long long f(long long n)
{
    if (n <= 2) return 1;
    return min(n, 2 + ((n - 2) % 3) + f((n - 2) / 3));
}

int main()
{
    long long n;
    scanf("%lld", &n);
    n++;
    printf("%lld", f(n) - 1);
    return 0;
}