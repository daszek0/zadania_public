// Jakub Daszkiewicz
// zadanie Podatki

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int t, b[1000001], mv = 0, a = 0;
    fill(b, b+1000001, 0);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        if (t > mv) mv = t;
        if (t != 0) b[t]++;
    }
    bool tt = false;
    for (int i=mv; i>1; i--)
    {
        if (b[i] == 0) continue;
        if (b[i] % 2) //nieparzysta
        {
            if (tt)
            {
                a += 3*b[i]/2+1;
                b[i-2] += b[i]/2+1;
                b[i-1] += b[i]/2;
                b[i] = 0;
            }
            else
            {
                a += 2*(b[i]/2)+(b[i]/2+1);
                b[i-1] += b[i]/2+1;
                b[i-2] += b[i]/2;
                b[i] = 0;
            }
            tt ^= 1;
        }
        else
        {
            a += 3*b[i]/2;
            b[i-2] += b[i]/2;
            b[i-1] += b[i]/2;
            b[i] = 0;
        }
    }
    if (!tt && b[1])
    {
        a++;
    }
    printf("%d", a);
    return 0;
}