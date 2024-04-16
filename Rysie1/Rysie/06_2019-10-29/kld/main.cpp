#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long long nwd(unsigned long long a, unsigned long long b)
{
    unsigned long long r;
    if (a == b)
        return a;
    else if (a > b)
    {
        do
        {
            r = a%b;
            a = b;
            b = r;
        } while (r != 0);
        return a;
    }
    else if (a < b)
    {
        do
        {
            r = b%a;
            b = a;
            a = r;
        } while (r != 0);
        return b;
    }
}

unsigned long long nww(unsigned long long a, unsigned long long b)
{
    return a*b/nwd(a,b);
}

int main()
{
    int n, r = 1;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        r = nww(r, i);
    }
    printf("%d", r);
    return 0;
}
