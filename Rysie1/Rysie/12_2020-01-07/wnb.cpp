// Jakub Daszkiewicz
// zadanie Wypisz N do 1

#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=n; i>0; i--)
    {
        printf("%d\n", i);
    }
    return 0;
}