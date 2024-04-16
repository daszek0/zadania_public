// Jakub Daszkiewicz
// zadanie Szkolenie

#include <stdio.h>

int n, m, l, t, b[200000], a = 0;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l);
        for (int j = 0; j < l; j++)
        {
            scanf("%d", &t);
            b[t - 1]++;
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (b[i] > b[a])
            a = i;
    }
    printf("%d", a + 1);
    return 0;
}