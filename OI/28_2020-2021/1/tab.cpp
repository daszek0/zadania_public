// Jakub Daszkiewicz
// zadanie Tablica binarna

#include <stdio.h>
#include <bitset>

using namespace std;

int main()
{
    int X, Y, q;
    scanf("%d %d %d", &X, &Y, &q);
    bitset<1000> b[1000];
    for (int i = 0; i < 1000; i++)
        b[i].reset();
    int y1, x1, y2, x2;
    long long a = 0;
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        y1--;
        x1--;
        y2--;
        x2--;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (b[x2][y2])
            a--;
        else
            a++;
        b[x2].flip(y2);
        if (x1 > 0)
        {
            if (b[x1 - 1][y2])
                a--;
            else
                a++;
            b[x1 - 1].flip(y2);
        }
        if (y1 > 0)
        {
            if (b[x2][y1 - 1])
                a--;
            else
                a++;
            b[x2].flip(y1 - 1);
        }
        if (x1 > 0 && y1 > 0)
        {
            if (b[x1 - 1][y1 - 1])
                a--;
            else
                a++;
            b[x1 - 1].flip(y1 - 1);
        }
        printf("%lld\n", a);
    }
    return 0;
}