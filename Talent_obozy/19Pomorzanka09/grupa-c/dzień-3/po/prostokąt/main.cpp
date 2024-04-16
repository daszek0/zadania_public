#include <bits/stdc++.h>

using namespace std;

int arraymax(int a[], int n)
{
    int r = -2147483648;
    for (int i=0; i<n; i++)
    {
        if (a[i] > r)
            r = a[i];
    }
    return r;
}

int arraymin(int a[], int n)
{
    int r = 2147483647;
    for (int i=0; i<n; i++)
    {
        if (a[i] < r)
            r = a[i];
    }
    return r;
}

int main()
{
    int n, a, b;
    scanf("%d", &n);
    int x[n], y[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    a = arraymax(x, n) - arraymin(x, n);
    b = arraymax(y, n) - arraymin(y, n);
    if (a == 0) a++;
    if (b == 0) b++;
    printf("%d", a * b);
    return 0;
}
