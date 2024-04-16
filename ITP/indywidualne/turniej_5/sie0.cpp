// Jakub Daszkiewicz
// zadanie Sieć

#include <stdio.h>

using namespace std;

int main()
{
    int n, t;
    unsigned long long s = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        s += t;
    }
    switch (s % 2)
    {
        case 0:
        {
            printf("NIE");
            break;
        }
        case 1:
        {
            printf("TAK");
            break;
        }
    }
    return 0;
}