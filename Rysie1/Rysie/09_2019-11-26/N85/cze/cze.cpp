// Jakub Daszkiewicz
// zadanie Czekolada

#include <stdio.h>

using namespace std;

int main()
{
    int width, height, x[1001] = {0}, y[1001] = {0}, xm = 1, ym = 1, temp, r = 0;
    scanf("%d %d", &width, &height);
    for (int i=1; i<width; ++i)
    {
        scanf("%d", &temp);
        ++x[temp];
    }
    for (int i=1; i<height; ++i)
    {
        scanf("%d", &temp);
        ++y[temp];
    }
    for (int i=1000; i>=1; --i)
    {
        if (x[i] ^ 0)
        {
            r += i*x[i]*xm;
            ym += x[i];
        }
        if (y[i] ^ 0)
        {
            r += i*y[i]*ym;
            xm += y[i];
        }
    }
    printf("%d", r);
    return 0;
}