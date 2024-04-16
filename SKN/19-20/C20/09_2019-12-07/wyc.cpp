// Jakub Daszkiewicz
// zadanie Wycinanka

#include <stdio.h>

using namespace std;

int max_a(int a[], int n)
{
    int r = 0;
    for (int i=0; i<n; i++)
        if (a[i] > r) r = a[i];
    return r;
}

int main()
{
    int x, y, n;
    scanf("%d%d%d", &x, &y, &n);
    if (n == 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int v[4];
        v[0] = x-a;
        v[1] = a;
        v[2] = y-b;
        v[3] = b;
        printf("%d", max_a(v, 4)*max_a(v, 4));
    }
    else printf("Zabrakło czasu na zadanie");
    return 0;
}