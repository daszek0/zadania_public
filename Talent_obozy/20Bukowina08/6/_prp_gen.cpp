// Jakub Daszkiewicz
// zadanie prp generator

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    printf("100 100000");
    for (int i=0; i<100; i++)
    {
        printf("\n%d %d", rand() % 100000, rand() % 10000000);
    }
    return 0;
}