// Jakub Daszkiewicz
// zadanie Iloczyn liczb pierwszych

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

bool prime[1000001];

void prime_fill()
{
    fill(prime, prime + 1000001, true);
    prime[0] = false;
    prime[1] = false;
    for (int i=2; i*i <= 1000001; i++)
    {
        if (prime[i])
        {
            for (int j = i*i; j <= 1000001; j += i)
            {
                prime[j] = false;
            }
        }
        
    }
}

long long qpow(long long a, long long n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return a;
    else if (n%2 == 0)
    {
        long long r = qpow(a, n/2);
        return r*r;
    }
    else
    {
        long long r = qpow(a, n-1);
        return a*r;
    }
}

int main()
{
    prime_fill();
    // for (int i=0; i<100; i++) if (prime[i]) printf("%d ", i);
    int n, N, c, sqrtn;
    vector <pair <int, int>> f;
    while (true)
    {
        f.clear();
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", n);
        if (prime[n])
        {
            printf("1*%d\n", n);
        }
        else
        {
            sqrtn = sqrt(n);
            N = n;
            for (int i = 2; i*i < N; i++) // do pierwiastka
            {
                if (prime[i])
                {
                    c = 0;
                    while (n % i == 0)
                    {
                        n /= i;
                        c++;
                    }
                    if (c > 0)
                    {
                        // printf("%d*%d\n", c, i);
                        f.push_back({c, i});
                    }
                }
            }
            if (prime[sqrtn])
            {
                c = 0;
                while (n % sqrtn == 0)
                {
                    n /= sqrtn;
                    c++;
                }
                if (c > 0) f.push_back({c, sqrtn});
            }
            if (n != 1) printf("1*%d\n", n);
            for (int i=f.size()-1; i>=0; i--)
            {
                printf("%d*%d\n", f[i].first, f[i].second);
            }
        }
    }
    return 0;
}