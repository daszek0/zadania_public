// Jakub Daszkiewicz
// zadanie Gra

#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int s[n + 1];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &s[i]);
    }
    s[n] = 0;
    sort(s, s + n + 1, greater<int>());
    int i = 1;
    while (s[i] > i) i++;
    int j = i/*  - 1 */;
    while (s[j] == i) j++;
    if (((s[i - 1] - i) & 1) || ((j - i) & 1)) printf("Wiki");
    else printf("Pedia");
    return 0;
}