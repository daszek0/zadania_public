// Jakub Daszkiewicz
// zadanie Liczba zbiorów n-k-specjalnych

#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if ((n * n + n) / 4 > k)
    {
        printf("0");
        return 0;
    }
    
    return 0;
}