// Jakub Daszkiewicz
// zadanie Podciągi

#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 1)
    {
        printf("0");
        return 0;
    }
    int a[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    return 0;
}