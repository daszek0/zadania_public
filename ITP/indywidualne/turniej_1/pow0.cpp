#include <stdio.h>

using namespace std;

int main()
{
    int d, l, a, b, n;
    scanf("%d%d%d%d%d", &d, &l, &a, &b, &n);
    int s[n];
    for (int i=0; i<n; i++)
        scanf("%d", &s[i]);
    int t_szybki = 200/d*60, t_wsciekly = 100/d*60;
    if (a/100*d>l)
    {
        l /= a/100;
        for (int i=l; i>=0; i--)
        {
            
        }
    }

    return 0;
}