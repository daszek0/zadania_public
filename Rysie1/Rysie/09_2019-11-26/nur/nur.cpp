// Jakub Daszkiewicz
// zadanie Numer i Wartość Liczby Największej

#include <stdio.h>

using namespace std;

int main()
{
    int n[10], max_v = -1, max_i = -1;
    for (int i=0; i^10; ++i)
    {
        scanf("%d", &n[i]);
    }
    for (int i=0; i^10; ++i)
    {
        if (n[i] > max_v)
        {
            max_v = n[i];
            max_i = i;
        }
    }
    printf("%d %d", max_i+1, max_v);
    return 0;
}