#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int c[4];
    for (int i=0; i<4; i++)
    {
        scanf("%d", &c[i]);
    }
    int a = 0;
    for (int i=0; i<4; i++)
    {
        a += c[i];
    }
    a /= 3;
    for (int i=0; i<4; i++)
    {
        printf("%d ", a-c[i]);
    }
    return 0;
}
