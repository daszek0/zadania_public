// Wild Algorithm Rangers
// zadanie Bardzo wydajna tablica

#include <stdio.h>

using namespace std;

int n;
int tab[1000001];
int ti, ti1;
char tc;
unsigned long long s;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &ti);
        tab[ti]++;
        s += ti;
    }
    scanf("%d\n", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%c", &tc);
        if (tc == 'P')
        {
            scanf(" %d %d\n", &ti, &ti1);
            s += tab[ti] * (ti1 - ti);
            tab[ti1] += tab[ti];
            tab[ti] = 0;
        }
        else if (tc == 'S')
        {
            scanf("\n");
            printf("%llu\n", s);
        }
    }
    return 0;
}