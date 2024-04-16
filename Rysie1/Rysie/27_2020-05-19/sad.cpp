// Jakub Daszkiewicz
// zadanie Sad

#include <stdio.h>
#include <algorithm>

using namespace std;

struct point
{
    long long x, y;
};


int main()
{
    point n[3];
    for (int i=0; i<3; i++) scanf("%lld %lld", &n[i].x, &n[i].y);
    long long P2 = abs((n[1].x - n[0].x)*(n[2].y - n[0].y) - (n[2].x - n[0].x)*(n[1].y - n[0].y));
    long long op = __gcd(abs(n[1].x - n[0].x), abs(n[1].y - n[0].y)) + __gcd(abs(n[2].x - n[1].x), abs(n[2].y - n[1].y)) + __gcd(abs(n[0].x - n[2].x), abs(n[0].y - n[2].y));
    printf("%lld", (P2 - op)/2 + 1);
    return 0;
}