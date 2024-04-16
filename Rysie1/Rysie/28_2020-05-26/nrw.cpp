// Jakub Daszkiewicz
// zadanie Nierówności

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    bool l[8];
    fill(l, l+8, true);
    int n;
    scanf("%d", &n);
    char l0, s, l1;
    for (int i=0; i<n; i++)
    {
        getchar_unlocked();
        l0 = getchar_unlocked();
        s = getchar_unlocked();
        l1 = getchar_unlocked();
        if (s == '<') l[l0 - 'A'] = false;
        else l[l1 - 'A'] = false;
    }
    for (int i=0; i<8; i++)
    {
        if (l[i]) putchar_unlocked(i + 'A');
    }
    return 0;
}