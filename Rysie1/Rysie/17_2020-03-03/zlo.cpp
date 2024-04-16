// Jakub Daszkiewicz
// zadanie Złożone

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n, i;
    while (cin>>n)
    {
        i = 6;
        while (n % 2 == 0)
        {
            printf("2");
            n /= 2;
            if (n != 1) printf("*");
        }
        while (n % 3 == 0)
        {
            printf("3");
            n /= 3;
            if (n != 1) printf("*");
        }
        while ((i-1)*(i-1) <= n)
        {
            while (n % (i-1) == 0)
            {
                printf("%d", (i-1));
                n /= (i-1);
                if (n != 1) printf("*");
            }
            while (n % (i+1) == 0)
            {
                printf("%d", (i+1));
                n /= (i+1);
                if (n != 1) printf("*");
            }
            i += 6;
        }
        if (n != 1)
        {
            printf("%d", n);
        }
        printf("\n");
    }
    return 0;
}