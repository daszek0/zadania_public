// Jakub Daszkiewicz
// zadanie Liczba uczestników klubu Talent

#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    unsigned long long r = 0;
    char s[10];
    unsigned long long n;
    while (scanf("%s", &s) != EOF)
    {
        scanf("%llu", &n);
        if (strlen(s) % 2 == 1) r += n;
        else r -= n;
    }
    printf("%llu", r);
    return 0;
}