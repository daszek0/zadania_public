// Jakub Daszkiewicz
// zadanie Gra w kamyki

#include <stdio.h>

using namespace std;

int main()
{
    int z, n, k;
    scanf("%d", &z);
    for (int p=0; p^z; ++p)
    {
        scanf("%d %d", &n, &k);
        if (n % (k+1) == 0) printf("Wiktor\n");
        else printf("Hektor\n");
    }
    return 0;
}