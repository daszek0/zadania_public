// Daszek
// Vestigium 

#include <stdio.h>

using namespace std;

int main()
{
    int t, n, k, r, c;
    bool l;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        k = 0;
        r = 0;
        c = 0;
        scanf("%d", &n);
        int tab[n][n];
        for (int ii=0; ii<n; ii++)
        {
            for (int iii=0; iii<n; iii++)
            {
                scanf("%d", &tab[ii][iii]);
            }
        }
        for (int ii=0; ii<n; ii++)
        {
            k += tab[ii][ii];
        }
        for (int ii=0; ii<n; ii++)
        {
            l = 0;
            for (int iii=0; iii<n && !l; iii++)
            {
                for (int iiii=iii+1; iiii<n && !l; iiii++)
                {
                    if (tab[ii][iii] == tab[ii][iiii])
                    {
                        r++;
                        l = 1;
                    }
                }
            }
        }
        for (int ii=0; ii<n; ii++)
        {
            l = 0;
            for (int iii=0; iii<n && !l; iii++)
            {
                for (int iiii=iii+1; iiii<n && !l; iiii++)
                {
                    if (tab[iii][ii] == tab[iiii][ii])
                    {
                        c++;
                        l = 1;
                    }
                }
            }
        }
        printf("Case #%d: %d %d %d\n", i+1, k, r, c);
    }
    return 0;
}