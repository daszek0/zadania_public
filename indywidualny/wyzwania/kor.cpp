// Jakub Daszkiewicz
// zadanie Korale

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar_unlocked();
    char bf, bp, b;
    bf = getchar_unlocked();
    b = bf;
    for (int i = 1; i < n; i++)
    {
        bp = b;
        b = getchar_unlocked();
        if (bp == b)
        {
            printf("NIE");
            return 0;
        }
    }
    if (b == bf)
        printf("NIE");
    else
        printf("TAK");
    return 0;
}