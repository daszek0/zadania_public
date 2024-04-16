#include <stdio.h>

using namespace std;

int main()
{
    int z;
    scanf("%d", &z);
    for (int p=0; p<z; ++p)
    {
        unsigned int n, k, o = 0;
        scanf("%u %u", &n, &k);
        while (n > k*2)
        {
            n -= k;
            ++o;
        }
        if (n > k+1)
        {
            if (o%2 == 0) printf("Hektor\n");
            else printf("Wiktor\n");
        }
        else
        {
            if (o%2 == 0) printf("Wiktor\n");
            else printf("Hektor\n");
        }
    }
    return 0;
}