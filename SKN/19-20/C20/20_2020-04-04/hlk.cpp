// Jakub Daszkiewicz
// zadanie Helikopter

#include <stdio.h>

using namespace std;

int main()
{
    int d;
    scanf("%d", &d);
    for (int i=0; i<d; i++)
    {
        printf("H");
        for (int j=1; j<d-1; j++) if (i != d/2) printf(" "); else printf("H");
        printf("H\n");
    }
    return 0;
}