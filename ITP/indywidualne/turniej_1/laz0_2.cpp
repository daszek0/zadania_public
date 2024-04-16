#include <stdio.h>

using namespace std;

int main()
{
    unsigned long long n, w;
    scanf("%llu %llu", &n, &w);
    for (unsigned long long i=n/2;; i--)
    {
        if (n-i == w/i)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}