// Jakub Daszkiewicz
// zadanie Kulki

#include <stdio.h>

using namespace std;

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);
    int ai;
    for (int i=1; i<=b; i++)
    {
        if (i == 1 || i == b - 1) ai = n - b + 1;
        else if (i > n / 2) ai = 0;
        else
        {
            // coś
        }
        printf("%d\n", ai);
    }
    return 0;
}