// Jakub Daszkiewicz
// zadanie Nierówności

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    pair <char, char> p[n];
    char sign;
    for (int i=0; i<n; i++)
    {
        getchar_unlocked();
        scanf("%c%c%c", &p[i].first, &sign, &p[i].second);
        if (sign == '<') swap(p[i].first, p[i].second);
    }
    sort(p, p+n);
    for (int i=1; i<n; i++)
    {
        if (p[i].first == p[0].second) p[0].second = p[i].second;
        else if (p[i].second == p[0].first) p[0].first = p[i].first;
    }
    printf("%c", p[0].first);
    return 0;
}