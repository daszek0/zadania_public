// Jakub Daszkiewicz
// zadanie Liczby królewskie

#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        k--;
        k <<= 1;
        if (__builtin_popcount(k) & 1) printf("%d\n", k + 1);
        else printf("%d\n", k);
    }
    return 0;
}