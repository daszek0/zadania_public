#include <bits/stdc++.h>

using namespace std;

int max_(int a[], int length)
{
    int r = a[0];
    for (int i=1; i<length; ++i)
    {
        if (a[i] > r) r = a[i];
    }
    return r;
}

void max_del(int a[], int length)
{
    int r = 0;
    for (int i=1; i<length; ++i)
    {
        if (a[i] > a[r]) r = i;
    }
    a[r] = -1;
}


int main()
{
    unsigned long long r = 0;
    int m, n;
    scanf("%d %d", &m, &n);
    int x[m-1], y[n-1], xo[m-1], yo[n-1];
    for (int i=0; i<m-1; ++i)
    {
        scanf("%d", &x[i]);
        xo[i] = x[i];
    }
    for (int i=0; i<n-1; ++i)
    {
        scanf("%d", &y[i]);
        yo[i] = y[i];
    }

    int xm = 1, ym = 1;
    int max_x, max_y;
    for (int i=0; i<m+n-2; ++i)
    {
        max_x = max_(x, m-1);
        max_y = max_(y, n-1);
        if (max_x > max_y)
        {
            r += max_x;
            max_del(x, m-1);
            for (int j=0; j<m-1; ++j)
            {
                y[j] += yo[j];
            }
        }
        else
        {
            r += max_y;
            max_del(y, n-1);
            for (int j=0; j<n-1; ++j)
            {
                x[j] += xo[j];
            }
        }
    }
    printf("%llu", r);
    return 0;
}