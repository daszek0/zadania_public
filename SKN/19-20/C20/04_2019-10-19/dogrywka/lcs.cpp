// Jakub Daszkiewicz
// zadanie Łączenie słów

#include <stdio.h>
#include <string.h>

using namespace std;

const int mod = 1000000007;
unsigned long long fib[333334];

char w[1000001];

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
    int n;
    scanf("%d", &n);
    unsigned long long r, l;
    int kot;
    for (int i=0; i<n; i++)
    {
        scanf("%s", w);
        r = 1;
        l = strlen(w);
        kot = 0;
        if (l>3)
        {
            for (int j=1; j<l-3; j++)
            {
                if (w[j] == 'k' && w[j+1] == 'o' && w[j+2] == 't')
                {
                    j += 2;
                    kot++;
                }
                else
                {
                    r *= fib[kot];
                    r %= mod;
                    kot = 0;
                }
            }
            r *= fib[kot];
            r %= mod;
        }
        printf("%llu\n", r);
    }
    return 0;
}