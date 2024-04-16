// Jakub Daszkiewicz
// zadanie Gra

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int s[n + 1];
    s[0] = 0;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    int c = 0, ic = 0;
    bool ap = true;
    int a = 0, b = 0;
    while (c < n)
    {
        do
        {
            c++;
        } while (s[c + 1] - s[ic] >= s[ic + 1] - s[ic] && (c < n - 1 && s[c + 1] - s[c] < 0 && s[c + 2] - s[c + 1] < 0 && s[c + 1] - s[c] > s[c + 2] - s[c + 1]) && c < n);
        if (ap) a += s[c] - s[ic];
        else b += s[c] - s[ic];
        ap ^= 1;
        ic = c;
    }
    printf("%d", a - b);
    return 0;
}