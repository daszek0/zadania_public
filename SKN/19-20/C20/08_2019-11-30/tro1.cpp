#include <stdio.h>

using namespace std;

void sort_tab(double tab[], int size)
{
    double minimal;
    int taken;
    for (int i=0; i<size; ++i)
    {
        minimal = tab[i];
        for (int j=i+1; j<size; ++j)
        {
            if (tab[j] < minimal)
            {
                minimal = tab[j];
                taken = j;
            }
        }
        tab[taken] = tab[i];
        tab[i] = minimal;
    }
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    double a[n];
    for (int i=0; i<n; ++i)
    {
        scanf("%lf/%d", &a[i], &temp);
        a[i] /= temp;
    }
    sort_tab(a, n);
    if (a[0]+a[1] > a[n-1]) printf("TAK");
    else printf("NIE");
    return 0;
}