// Jakub Daszkiewicz
// zadanie Złożone

#include <stdio.h>
#include <iostream>

using namespace std;

const int p[40] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173};

int main()
{
    int n;
    while (cin>>n)
    {
        for (int i=0; i<40; i++)
        {
            if (p[i] > n) break;
            while (n%p[i] == 0)
            {
                printf("%d", p[i]);
                n /= p[i];
                if (n ^ 1) printf("*");
            }
        }
        if (n ^ 1) printf("%d", n);
        printf("\n");
    }
    return 0;
}