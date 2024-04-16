// Jakub Daszkiewicz
// zadanie Kwadraty

#include <stdio.h>
#include <algorithm>

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
    int x = abs(a - b) / 2;
    printf("%d", x * x - min(a, b));
    return 0;
}