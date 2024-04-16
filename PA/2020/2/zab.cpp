// Jakub Daszkiewicz
// zadanie Zabawki [C]

#include <stdio.h>

int n, t0[26], t1[26];
char t;

int main()
{
    scanf("%d", &n);
    getchar_unlocked();
    for (int i = 0; i < n; i++)
    {
        t = getchar_unlocked();
        t0[t - 'a']++;
    }
    getchar_unlocked();
    for (int i = 0; i < n; i++)
    {
        t = getchar_unlocked();
        t1[t - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (t0[i] != t1[i])
        {
            printf("NIE\n");
            return 0;
        }
    }
    printf("TAK\n");
    return 0;
}