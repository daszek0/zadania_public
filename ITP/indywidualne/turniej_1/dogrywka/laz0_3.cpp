#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    unsigned long long n, w;
    scanf("%llu%llu", &n, &w);
    if (n/2 < sqrt(w))
    {
        for (int i=n/2; i>=0; i--)
        {
            if (n-i == w/i)
            {
                printf("%d", i);
                break;
            }
        }
    }
    else
    {
        for (int i=sqrt(w); i>=0; i--)
        {
            if (n-i == w/i)
            {
                printf("%d", i);
                break;
            }
        }
    }
    return 0;
}