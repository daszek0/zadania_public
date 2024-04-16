// Jakub Daszkiewicz
// zadanie Kwadrat

#include <stdio.h>

using namespace std;

int main()
{
    unsigned long long n;
    scanf("%llu", &n);
    n--;
    printf("%llu", (10*n - 6)*(n*n));
    return 0;
}