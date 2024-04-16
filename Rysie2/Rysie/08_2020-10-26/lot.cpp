// Jakub Daszkiewicz
// zadanie Loteria

#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    char a, b;
    int c = 1, ans = 0;
    a = getchar_unlocked();
    while (a < 'A' || a > 'Z') a = getchar_unlocked();
    b = getchar_unlocked();
    while (b >= 'A' && b <= 'Z')
    {
        if (a == b)
        {
            c++;
        }
        else
        {
            ans += (c >> 1);
            c = 1;
        }
        a = b;
        b = getchar_unlocked();
    }
    ans += (c >> 1);
    printf("%d", ans);
    return 0;
}