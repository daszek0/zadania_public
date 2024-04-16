// Jakub Daszkiewicz
// zadanie Funkcja

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b, gcd;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        if (a * b > 0) printf("-");
        a = abs(a);
        b = abs(b);
        gcd = __gcd(a, b);
        a /= gcd;
        b /= gcd;
        printf("%d", b);
        if (a != 1) printf("/%d", a);
        printf("\n");
    }
    return 0;
}