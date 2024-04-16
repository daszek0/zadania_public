#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i=0; i<6; i++)
    {
        for (int j=i; j<6; j++)
        {
            if (i!=j) printf("%d^%d= %d\n", i, j, i^j);
        }
    }
    return 0;
}
