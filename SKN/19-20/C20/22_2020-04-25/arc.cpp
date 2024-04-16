// Jakub Daszkiewicz
// zadanie Archaizm

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar_unlocked();
    char c, pc;
    int tr = 1, r = 1;
    pc = getchar_unlocked();
    for (int i=1; i<n; i++)
    {
        c = getchar_unlocked();
        if (c == pc)
        {
            r = max(r, tr);
            tr = 1;
        }
        else
        {
            tr++;
        }
        pc = c;
    }
    r = max(r, tr);
    printf("%d", r);
    return 0;
}
