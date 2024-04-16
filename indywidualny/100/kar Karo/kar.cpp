// Jakub Daszkiewicz
// zadanie Karo

#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int i = 1, j;
    for (i; i<=n; i++)
    {
        j = 1;
        for (j; j<=n-i+1; j++) printf(" ");
        for (j; j<=n+i; j++) printf("X");
        for (j; j<=2*n; j++) printf(" ");
        printf("\n");
    }
    // for (int k=0; k<n; k++) printf("X");
    // printf("\n");
    for (i; i>0; i--)
    {
        j = 1;
        for (j; j<=n-i+1; j++) printf(" ");
        for (j; j<=n+i; j++) printf("X");
        for (j; j<=2*n; j++) printf(" ");
        printf("\n");
    }
    return 0;
}