#include <stdio.h>
#include <algorithm>
// #include <math.h>

using namespace std;

void sort_tab(int tab[])
{
    for (int i=0; i<4; ++i)
    {
        for (int j=i+1; j<4; ++j)
        {
            if (tab[j] < tab[i])
            {
                swap(tab[i], tab[j]);
            }
        }
    }
    
}

int main()
{
    int x[4], y[4];
    for (int i=0; i<4; ++i)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    if ((x[0] <= x[2] && x[2] <= x[1] && x[1] <= x[3] && y[3] <= y[1] && y[1] <= y[2] && y[2] <= y[0]) || (x[0] <= x[2] && x[2] <= x[1] && x[1] <= x[3] && y[1] <= y[3] && y[3] <= y[0] && y[0] <= y[2]) || (x[2] <= x[0] && x[0] <= x[3] && x[3] <= x[1] && y[3] <= y[1] && y[1] <= y[2] && y[2] <= y[0]) || (x[2] <= x[0] && x[0] <= x[3] && x[3] <= x[1] && y[1] <= y[3] && y[3] <= y[0] && y[0] <= y[1]))
    {
        sort_tab(x);
        sort_tab(y);
        unsigned long long a = x[2] - x[1];
        unsigned long long b = y[2] - y[1];
        printf("%llu", a*b);
    }
    else printf("0");
    return 0;
}