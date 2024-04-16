#include <stdio.h>

using namespace std;

int main()
{
    for (int i=0; i<12; i -= -1)
    {
        int n;
        scanf("%d", &n);
        if (n%2 == 0) printf("parzysta\n");
        else printf("nieparzysta\n");
    }
    return 0;
}