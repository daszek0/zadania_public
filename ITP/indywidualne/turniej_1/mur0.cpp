#include <stdio.h>

using namespace std;

int main()
{
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    a += b*2;
    a *= 10;
    a /= l;
    printf("%d", a*10);
    return 0;
}