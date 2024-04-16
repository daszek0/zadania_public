// Jakub Daszkiewicz
// zadanie Odległość

#include <stdio.h>

using namespace std;

int main()
{
    int a;
    long double b = 0, t;
    scanf("%d", &a);
    for (int i=0; i<a; i++)
    {
        scanf("%Lf", &t);
        b += t;
    }
    printf("%.2Lf", b/a);
    return 0;
}