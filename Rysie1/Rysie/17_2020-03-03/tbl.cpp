// Jakub Daszkiewicz
// zadanie Tablica

#include <stdio.h>

using namespace std;

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int tab[m*n+1];
    for (int i=1; i<m*n+1; i++)
    {
        scanf("%d", &tab[i]);
    }
    int r = 0;
    for (int i=k; i<m*n+1; i+=k)
    {
        r += tab[i];
    }
    printf("%d", r);
    return 0;
}