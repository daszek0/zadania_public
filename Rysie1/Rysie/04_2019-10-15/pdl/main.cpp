#include <stdio.h>

using namespace std;

int main()
{
    int p, l;
    float r;
    scanf("%d %d", &p, &l);
    r = (float)l/100;
    r *= p;
    printf("%.0f", r);
    return 0;
}
