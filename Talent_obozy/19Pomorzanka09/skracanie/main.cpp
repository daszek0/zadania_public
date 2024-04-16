#include <stdio.h>

using namespace std;

int nwd(unsigned long long a, unsigned long long b)
{
    if(a>b)
    {
        for(unsigned long long i=b; i>0; i--)
            if(a%i==0 && b%i==0)
                return i;
    }
    else if(a<b)
    {
        for(unsigned long long i=a; i>0; i--)
            if(a%i==0 && b%i==0)
                return i;
    }
    else if(a==b)
        return a;
}


void shorten(unsigned long long &a, unsigned long long &b)
{
    unsigned long long aa = a/nwd(a,b);
    unsigned long long bb = b/nwd(a,b);
    a = aa;
    b = bb;
}

int main()
{
    unsigned long long a, b;
    scanf("%lld %lld", &a, &b);
    shorten(a, b);
    printf("%lld / %lld", a, b);
    return 0;
}
