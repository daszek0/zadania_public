// Jakub Daszkiewicz
// zadanie Mleczarz

#include <stdio.h>

using namespace std;

int main()
{
    int t0, t1, r = 0;
    while (scanf("%d %d", &t0, &t1) != EOF)
    {
        r += t0 * t1;
    }
    printf("%d", r);
    return 0;
}