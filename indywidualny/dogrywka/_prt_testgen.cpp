// Jakub Daszkiewicz
// zadanie prt test generator

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    printf("%d %d", 100000, 2137);
    printf("\n%d", rand() % 1000000000);
    for (int i=1; i<100000; i++)
    {
        printf(" %d", rand() % 1000000000);
    }
    printf("\n%d", 100000);
    for (int i=0; i<100000; i++)
    {
        printf("\n%d", rand() % 100000);
    }
    return 0;
}