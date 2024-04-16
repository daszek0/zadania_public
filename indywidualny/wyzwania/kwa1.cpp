// Jakub Daszkiewicz
// zadanie Kwadraty

#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if ((a - b) % 2 == 0)
    {
        printf("brak");
        return 0;
    }
    int x = -min(a, b);
    a += x;
    b += x;
    double af, bf;
    while (true)
    {
        if (modf(sqrt(a), &af) == 0 && modf(sqrt(b), &bf) == 0)
        {
            printf("%d", x);
            return 0;
        }
        a++;
        b++;
        x++;
    }
    return 0;
}