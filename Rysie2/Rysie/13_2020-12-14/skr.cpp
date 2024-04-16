// Jakub Daszkiewicz
// zadanie Skarpety

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    long long n, m;
    long long a = 0;
    scanf("%lld %lld", &n, &m);
    long long s[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &s[i]);
    }
    if (*max_element(s, s + m) < n)
    {
        printf("OJEJKU");
        return 0;
    }
    sort(s, s + m);
    long long i = 0;
    while (s[i] < n)
    {
        a += s[i];
        i++;
    }
    a += (n - 1) * (m - i);
    printf("%lld", a + 1);
    return 0;
}