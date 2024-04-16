// Jakub Daszkiewicz
// zadanie Liczby drugie

#include <stdio.h>
#include <math.h>

#define ull unsigned long long

using namespace std;

bool if_prime(ull n)
{
    switch(n)
    {
        case 1: return false;
        case 2:
        case 3: return true;
    }
    if (n % 2 == 0 || n % 3 == 0) return false;
    // for (ull i=1; 6*i+1<=sqrt(n); i++)
    // {
    //     if (n % (6*i-1) == 0 || n % (6*i+1) == 0) return false;
    // }
    for (ull i=3; i*i<=n; i+=2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

unsigned long long pow10(unsigned int n)
{
    switch(n)
    {
        case  1: return 10;
        case  2: return 100;
        case  3: return 1000;
        case  4: return 10000;
        case  5: return 100000;
        case  6: return 1000000;
        case  7: return 10000000;
        case  8: return 100000000;
        case  9: return 1000000000;
        case 10: return 10000000000;
        case 11: return 100000000000;
        case 12: return 1000000000000;
        case 13: return 10000000000000;
    }
}

int main()
{
    ull n, a, b;
    scanf("%llu", &n);
    int checks = log10(n)+1;
    bool r = false;
    for (unsigned int i=1; i<=checks; i++)
    {
        a = n / pow10(i);
        b = n % pow10(i);
        if ((int)ceil(log10(a))+(int)ceil(log10(b)) != checks) continue;
        if (if_prime(a) && if_prime(b))
        {
            r = true;
            break;
        }
    }
    if (r) printf("TAK");
    else printf("NIE");
    return 0;
}