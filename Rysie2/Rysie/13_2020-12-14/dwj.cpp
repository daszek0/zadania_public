// Jakub Daszkiewicz
// zadanie Dwójki

#include <stdio.h>

int main()
{
    int n, a = 0, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        a ^= t;
    }
    printf("%d", a);
    return 0;
}