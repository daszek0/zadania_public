// Wild Algorithm Rangers
// zadanie Dominik i słownik

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    char c[2];
    int n[2];
    scanf("%c %c", &c[0], &c[1]);
    for (int i=0; i<2; i++)
    {
        n[i] = (int)c[i];
    }
    if (abs((int)(c[0]-c[1])) == 32)
    {
        if (c[0] < c[1])
        {
            printf("%c", c[0]);
        }
        else
        {
            printf("%c", c[1]);
        }
    }
    else
    {
        for (int i=0; i<2; i++)
        {
            if (c[i] > 96)
            {
                n[i] = (int)c[i] - 32;
            }
        }
        if (n[0] < n[1])
        {
            printf("%c", c[0]);
        }
        else
        {
            printf("%c", c[1]);
        }
    }
    return 0;
}