// Jakub Daszkiewicz
// zadanie Wybór zadań [C]

#include <stdio.h>

int n, a[5][3];
char d, l;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        getchar_unlocked();
        d = getchar_unlocked();
        d -= '1';
        l = getchar_unlocked();
        l -= 'A';
        a[d][l]++;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] < 1)
            {
                printf("NIE");
                return 0;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (a[4][i] < 2)
        {
            printf("NIE");
            return 0;
        }
    }
    printf("TAK");
    return 0;
}