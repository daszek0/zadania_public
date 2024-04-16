// Jakub Daszkiewicz
// zadanie Hurtownia

#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int g[26] = {0};
    bool ge[26] = {0};
    char tc;
    int ti;
    for (int i=0; i<n; i++)
    {
        scanf("\n%c %d", &tc, &ti);
        g[(int)(tc - 'A')] += ti;
        ge[(int)(tc - 'A')] = 1;
    }
    for (char i='A'; i<='Z'; i++)
    {
        if (ge[(int)(i - 'A')] == 1)
        {
            printf("%c %d\n", i, g[(int)(i - 'A')]);
        }
    }
    return 0;
}