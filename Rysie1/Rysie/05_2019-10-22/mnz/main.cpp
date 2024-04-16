#include <stdio.h>

using namespace std;

int n, c11, c12, c21, c22;

int main()
{
    scanf("%d", &n);
    c11 = n/100;
    c12 = n-c11*100;
    c21 = n/10;
    c22 = n-c21*10;
    if (c11*c12 > c21*c22) printf("%d", c11*c12);
    else printf("%d", c21*c22);
    return 0;
}
