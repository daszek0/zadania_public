// Jakub Daszkiewicz
// zadanie dom test reverse

#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", n);
    int a, b;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("\n%d %d", b, a);
    }
    return 0;
}