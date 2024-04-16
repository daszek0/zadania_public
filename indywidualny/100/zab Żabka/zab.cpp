// Jakub Daszkiewicz
// zadanie Żabka

#include <stdio.h>

int main()
{
    int t;
    long long a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%lld %lld", &a, &b);
        while (b > 0)
        {
            if (b == a)
            {
                printf("TAK\n");
                break;
            }
            b >>= 1;
        }
        if (b == 0)
            printf("NIE\n");
    }
    return 0;
}