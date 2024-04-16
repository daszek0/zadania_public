#include <stdio.h>

using namespace std;

int main()
{
    int m, h;
    scanf("%d %d", &m, &h);
    int bmi = m*10000/(h*h);
    if (bmi < 15)
    {
        printf("NN!");
    }
    else if (bmi < 19)
    {
        printf("N");
    }
    else if (bmi < 26)
    {
        printf("OK");
    }
    else if (bmi < 31)
    {
        printf("W");
    }
    else if (bmi < 36)
    {
        printf("O1");
    }
    else if (bmi < 41)
    {
        printf("O2");
    }
    else
    {
        printf("OE!");
    }
    return 0;
}
