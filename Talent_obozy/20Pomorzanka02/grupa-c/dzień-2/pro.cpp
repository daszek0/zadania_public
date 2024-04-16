// Jakub Daszkiewicz
// zadanie Liczba prostokątów

#include <stdio.h>

using namespace std;

int main()
{
    while (true)
    {
        int n, r = 0;
        scanf("%d", &n);
        if (n == 0) break;
        for (int i=1; i*i<=n; i++)
        {
            if (n / i * i == n) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}