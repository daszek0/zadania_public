// Jakub Daszkiewicz
// zadanie Wspólne układanie

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int a[26];
    fill(a, a+26, 0);
    int j[26];
    fill(j, j+26, 0);
    int n, m, r = 0;
    scanf("%d %d\n", &n, &m);
    char t;
    for (int i=0; i<n; i++)
    {
        t = getchar_unlocked();
        a[int(t - 'a')]++;
    }
    getchar_unlocked();
    for (int i=0; i<m; i++)
    {
        t = getchar_unlocked();
        j[int(t - 'a')]++;
    }
    for (int i=0; i<26; i++)
    {
        r += min(a[i], j[i]);
    }
    printf("%d", r);
    return 0;
}