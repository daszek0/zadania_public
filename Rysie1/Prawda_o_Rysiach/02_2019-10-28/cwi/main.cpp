#include <stdio.h>

using namespace std;

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if (y>0)
    {
        if (x>0)
            printf("I");
        else
            printf("II");
    }
    else
    {
        if (x<0)
            printf("III");
        else
            printf("IV");
    }
    return 0;
}
