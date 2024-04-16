// Jakub Daszkiewicz
// zadanie kds test generator

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    printf("10\n");
    for (int i=0; i<10; i++)
    {
        printf("100000\n");
        printf("0");
        for (int i=1; i<100000; i++)
        {
            printf(" %d", rand() % i);
        }
        printf("\n");
    }
    return 0;
}