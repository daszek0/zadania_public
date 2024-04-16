#include <stdio.h>

using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    if (m == n)
    {
        printf("%d=%d", m, n);
    }
    else if (m > n)
    {
        printf("%d>%d", m, n);
    }
    else if (m < n)
    {
        printf("%d<%d", m, n);
    }
    return 0;
}
