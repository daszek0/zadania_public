// Jakub Daszkiewicz
// zadanie Rower

#include <stdio.h>

using namespace std;

int main()
{
    unsigned long long d, o, p, t;
    scanf("%llu %llu %llu %llu", &d, &o, &p, &t);
    printf("%llu", t*d/p/o);
    return 0;
}