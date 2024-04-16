#include <stdio.h>

using namespace std;

int main()
{
    unsigned long long n, r = 0;
    //unsigned long long a;
    scanf("%llu", &n);
    for (unsigned long long i=n; i>0; --i)
    {
        //a = i%1000000007;
        i %= 1000000007;
        r += i;
        r %= 1000000007;
    }
    printf("%llu", r);
    return 0;
}
