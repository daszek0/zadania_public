// Jakub Daszkiewicz
// zadanie Pierniki

#include <stdio.h>

using namespace std;

void qinp(int *n)
{
    int r = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();
    while (c >= '0' && c <= '9')
    {
        r = (r << 3) + (r << 1) + c - '0';
        c = getchar_unlocked();
    }
    *n = r;
}

int main()
{
    int n, l, q;
    qinp(&n);
    qinp(&l);
    // scanf("%d %d", &n, &l);
    int x[n];
    for (int i=0; i<n; i++)
    {
        qinp(&x[i]);
        // scanf("%d", &x[i]);
    }
    qinp(&q);
    // scanf("%d", &q);
    int k, s;
    long long a;
    for (int p=0; p<q; p++)
    {
        qinp(&k);
        // scanf("%d", &k);
        a = x[k - 1];
        s = 0;
        for (int i=k - 1; i>0; i--)
        {
            if ((k - i) % l == 0)
            {
                s = i;
                break;
            }
        }
        for (int i=s; i>0; i -= l)
        {
            a += x[i - 1];
        }
        printf("%lld\n", a);
    }
    return 0;
}