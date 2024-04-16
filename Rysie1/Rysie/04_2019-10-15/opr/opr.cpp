#include <stdio.h>

using namespace std;

int main()
{
    int A;
    scanf("%d", &A);
    if (A < 90)
    {
        printf("OSTRY");
    }
    else if (A == 90)
    {
        printf("PROSTY");
    }
    else if (A < 180)
    {
        printf("ROZWARTY");
    }
    return 0;
}
