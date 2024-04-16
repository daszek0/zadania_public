#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long int c[n], r = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%ld", &c[i]);
    }
    long int m = c[n-1];
    for (int i=n-1; i>=0; i--)
    {
        if (c[i] < m)
        {
            m = c[i];
        }
        r += m;
    }
    printf("%ld", r);
    return 0;
}
