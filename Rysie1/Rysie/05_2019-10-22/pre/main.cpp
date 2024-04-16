#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n;
    scanf("%llu", &n);
    unsigned long long a[n];
    //bool ab[n];
    for (unsigned long long i=0; i<n; i++)
    {
        a[i] = 0;
        //ab[i] = false;
    }
    for (unsigned long long i=0; i<n; i++)
    {
        for (unsigned long long j=i+1; j<n; j++)
        {
            //if (i != j)
            //{
                a[i] += i^j;
                //ab[i] = true;
            //}
        }
    }
    unsigned long long minim = 18446744073709551615;
    for (unsigned long long i=0; i<n; i++)
    {
        if (a[i] < minim /*&& ab[i] == true*/) minim = a[i];
    }
    printf("%llu", minim);

    return 0;
}
