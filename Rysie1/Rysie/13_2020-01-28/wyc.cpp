// Jakub Daszkiewicz
// zadanie Wycinek

#include <stdio.h>

using namespace std;

int tab_sum(int tab[], int begin, int end)
{
    int r = 0;
    for (int i=begin; i<end; i++)
    {
        r += tab[i];
    }
    return r;
}

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    int x[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x[i]);
    }
    int cl = n;
    int p, q;
    while ()
    {
        p = 0;
        q = p+cl;
        while (q < n)
        {
            
            p++;
            q++;
        }
    }
    return 0;
}