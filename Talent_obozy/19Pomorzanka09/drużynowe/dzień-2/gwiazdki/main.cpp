#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mark[7], r = 0;
    bool bad = false;
    for (int i=0; i<7; i++)
    {
        scanf("%d", &mark[i]);
    }
    for (int i=0; i<7; i++)
    {
        if (mark[i] == 6)
            r++;
        if (mark[i] == 2)
            bad = true;
    }
    if (bad == true || r == 0)
    {
        printf("NIE");
    }
    else
    {
        for (int i=0; i<r; i++)
            printf("*");
    }
    return 0;
}
