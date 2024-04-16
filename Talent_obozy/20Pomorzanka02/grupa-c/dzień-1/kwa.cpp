// Jakub Daszkiewicz
// zadanie Kwadrat

#include <stdio.h>
#include <math.h>
#define ull unsigned long long

using namespace std;

bool check(ull c)
{
    ull s = sqrt(c);
    if (s*s == c) return true;
    return false;
}

int main()
{
    unsigned n;
    scanf("%u", &n);
    ull c = n;
    while (true)
    {
        if (check(c))
        {
            printf("%llu", c);
            return 0;
        }
        c += n;
    }
    return 0;
}