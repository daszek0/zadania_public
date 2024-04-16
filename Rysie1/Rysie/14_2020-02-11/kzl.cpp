// Jakub Daszkiewicz
// zadanie K największych

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int l, k;
    scanf("%d %d", &l, &k);
    int tab[l];
    for (int i=0; i<l; i++)
    {
        scanf("%d", &tab[i]);
    }
    sort(tab, tab+l);
    for (int i=l-1; l-i<=k; i--)
    {
        printf("%d\n", tab[i]);
    }
    return 0;
}