// Jakub Daszkiewicz
// dzi generator

#include <stdio.h>

using namespace std;

int main()
{
    printf("2000\n");
    for (int i=0; i<2000; i++)
    {
        for (int j=0; j<2000; j++)
        {
            printf("0 ");
        }
        printf("\n");
    }
    return 0;
}