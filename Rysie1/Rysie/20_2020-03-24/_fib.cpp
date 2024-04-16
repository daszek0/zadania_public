// fib

#include <stdio.h>

using namespace std;

const int mod = 1000000007;
unsigned long long fib[333334];

void fib_count()
{
    fib[0] = 1;
    fib[1] = 2;
    for (int i=2; i<333334; i++)
    {
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
    }
}

int main()
{
    fib_count();
    printf("const int fib[333334] = {1");
    for (int i=1; i<333334; i++)
    {
        printf(", %d", fib[i]);
    }
    printf("};");
    return 0;
}