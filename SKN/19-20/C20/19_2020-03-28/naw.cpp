// Jakub Daszkiewicz
// zadanie Nawiasowanie

#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);
    char c;
    int co = 0, cc = 0;
    int ro = 0, rc = 0;
    for (int i=0; i<n; i++)
    {
        c = getchar_unlocked();
        if (c == '(')
        {
            co++;
        }
        else if (c == ')')
        {
            if (co == 0) ro++;
            else co--;
        }
    }
    if (co != 0) rc = co;
    printf("%d %d", ro, rc);
    return 0;
}