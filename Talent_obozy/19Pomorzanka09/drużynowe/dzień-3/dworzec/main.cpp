#include <bits/stdc++.h>

using namespace std;

long long nwd(long long a,long long b)
{
    long long result;
    if(a>b)
    {
        for(long long i=b;i>0;i--)
        {
            if(a%i==0 && b%i==0)
            {
                result=i;
                break;
            }
        }
    }
    else if(a<b)
    {
        for(long long i=a;i>0;i--)
        {
            if(a%i==0 && b%i==0)
            {
                result=i;
                break;
            }
        }
    }
    else if(a==b)
        result = a;
    return result;
}

long long nww2 (long long a, long long b)
{
    return a/nwd(a, b)*b;
}

long long nww4(long long x, long long y, long long z, long long t)
{
    return nww2(t,nww2(z,nww2(x,y)));
}

int main()
{
    long long x, y, z, t;
    scanf("%lld %lld %lld %lld", &x, &y, &z, &t);
    long long minutes = nww4(x, y, z, t), hours = 0;
    while (minutes >= 60)
    {
        hours++;
        minutes -= 60;
    }
    printf("%lld %lld", hours, minutes);
    return 0;
}
