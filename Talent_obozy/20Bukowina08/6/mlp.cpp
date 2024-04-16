// Jakub Daszkiewicz
// zadanie Mała pamięć

#include <stdio.h>

using namespace std;

int qpowm(int a, int n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n % 2) return (a * qpowm(a, n - 1)) % 37;
    int m = qpowm(a, n / 2) % 37;
    return (m * m) % 37;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar_unlocked();
    if (n == 0)
    {
        printf("NIE\n");
        return 0;
    }
    char c;
    int h = 0;
    for (int i=0; i<n/2; ++i)
    {
        c = getchar_unlocked();
        h += c * qpowm(2, i);
    }
    if (n % 2)
    {
        getchar_unlocked();
    }
    for (int i=n/2-1; i>=0; --i)
    {
        c = getchar_unlocked();
        h -= c * qpowm(2, i);
    }
    if (h) printf("NIE\n");
    else printf("TAK\n");
    return 0;
}