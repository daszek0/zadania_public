#include <stdio.h>
#include <math.h>

using namespace std;

bool prime(unsigned int n)
{
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0) return false;
    }
    return true;
}

int main()
{
    unsigned int q, b, e;
    scanf("%d", &q);
    for (unsigned int p=0; p<q; p++)
    {
        scanf("%u %u", &b, &e);
        if (b == 2)
        {
            if (e > 3) printf("4");
            else printf("NIE");
        }
        else
        {
            if (!prime(b)) printf("%u", b);
            else if (!prime(e)) printf("%u", e);
            else if (e-b > 0) printf("%u", b+1);
            else printf("NIE");
        }
        printf("\n");
    }
    return 0;
}