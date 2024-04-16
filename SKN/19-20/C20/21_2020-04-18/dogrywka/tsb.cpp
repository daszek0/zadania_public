// Jakub Daszkiewicz
// zadanie Tajny szyfr biurowca

#include <stdio.h>
#include <string.h>

using namespace std;

char c[250];

void minus1(int i)
{
    if (c[i] > '0')
    {
        c[i]--;
        return;
    }
    c[i] = '9';
    minus1(i - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    int rc[n];
    scanf("%s", &c);
    int lc = strlen(c) - 1;
    for (int i=n-1; i>=0; i--)
    {
        if (c[lc] >= '5')
        {
            rc[i] = (int)(c[lc] - '0') - 5;
            lc--;
        }
        else
        {
            rc[i] = (int)(c[lc] - '0') + 5;
            lc--;
            minus1(lc);
        }
    }
    int i = 0;
    while (c[i] == '0')
    {
        i++;
    }
    for (i; i<=lc; i++)
    {
        printf("%c", c[i]);
    }
    for (int i=0; i<n; i++)
    {
        printf("\n%d", rc[i]);
    }
    return 0;
}