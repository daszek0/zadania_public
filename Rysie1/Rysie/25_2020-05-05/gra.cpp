// Jakub Daszkiewicz
// zadanie Gra

#include <stdio.h>

using namespace std;

int main()
{
    int p;
    long n;
    scanf("%d", &p);
    for (int i=0; i<p; i++)
    {
        scanf("%ld", &n);
        if (n % 3 == 0) printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}