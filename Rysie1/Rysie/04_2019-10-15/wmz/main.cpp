#include <iostream>
#include <stdio.h>

#define mod 500000009

using namespace std;

int main()
{
    int h;
    unsigned long long x = 1, r = 1;
    scanf("%d", &h);
    for (int i=2; i<=h; ++i)
    {
        x = x*4%mod;
        r = (r+x)%mod;
    }
    printf("%lld", r);
    return 0;
}
