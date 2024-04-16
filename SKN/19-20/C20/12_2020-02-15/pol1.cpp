// Jakub Daszkiewicz
// zadanie Prawie pół-pierwsza

#include <stdio.h>
#include <vector>

using namespace std;

int p[78498];

bool prime(int n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    else if (n % 2 == 0) return false;
    for (int i=3; i*i<=n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void primegen()
{
    int c = 0;
    for (int i=2; i<=1000000; i++)
    {
        if (prime(i))
        {
            p[c] = i;
            c++;
        }
    }
}

int main()
{
    primegen();
    unsigned long long a, b;
    scanf("%llu %llu", &a, &b);
    int check, r = 0;
    for (int i=0; i<78498; i++)
    {
        if (p[i] * p[i] > b) break;
        for (int j=i; j<78498; j++)
        {
            check = p[i] * p[j];
            if (check > b) break;
            if (check >= a)
            {
                r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}