// Jakub Daszkiewicz
// zadanie Iloczyn liczb pierwszych

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

bool prime[1000001];

void prime_fill()
{
    fill(prime, prime + 1000001, true);
    prime[0] = false;
    prime[1] = false;
    for (int i=2; i*i <= 1000001; i++)
    {
        for (int j = 2; j*i < 1000001; j++)
        {
            prime[j*i] = false;
        }
    }
}

int main()
{
    prime_fill();
    // for (int i=0; i<100; i++) if (prime[i]) printf("%d ", i);
    int n, c;
    while (true)
    {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", n);
        for (int i = n; i > 1; i--)
        {
            if (prime[i])
            {
                c = 0;
                while (n % i == 0)
                {
                    n /= i;
                    c++;
                }
                if (c > 0) printf("%d*%d\n", c, i);
            }
        }
    }
    return 0;
}