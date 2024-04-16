// Jakub Daszkiewicz
// zadanie Bierki

// test: 10 7 1 2 8 10 6 1 7 9 9 => 7

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    sort(s, s + n);
    int p = n - 3, q = n - 1;
    int r = 0, rt = 0;
    while (p > 0)
    {
        if (s[p] + s[p + 1] > s[q])
        {
            p--;
            rt = q - p;
            r = max(r, rt);
        }
        else
        {
            q--;
        }
    }
    printf("%d\n", r);
    return 0;
}