// Jakub Daszkiewicz
// zadanie Okrągły Płotek

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q, n;
    scanf("%d", &q);
    for (int p=0; p<q; p++)
    {
        scanf("%d", &n);
        printf("1 ");
        for (int i=2; i<=n; i++)
            if (__gcd(n, i) == 1)
                printf("%d ", i);
        printf("\n");
    }
    return 0;
}