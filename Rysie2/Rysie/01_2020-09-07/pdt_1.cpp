// Jakub Daszkiewicz
// zadanie Podatki

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int m[n], a = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &m[i]);
        a += m[i] - (m[i] % 3);
        m[i] %= 3;
    }
    sort(m, m+n);
    reverse(m, m+n);
    for (int i=0; i<n; i++)
    {
        if (m[0] >= 1) a++;
        else break;
    }
    printf("%d", a);
    return 0;
}