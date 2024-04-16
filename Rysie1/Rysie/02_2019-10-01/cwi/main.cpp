#include <stdio.h>

using namespace std;

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if(y>0)
    {
        if(x>0)
        {
            printf("I");
        }
        else if(x<0)
        {
            printf("II");
        }
    }
    else if(y<0)
    {
        if(x>0)
        {
            printf("IV");
        }
        else if(x<0)
        {
            printf("III");
        }
    }
    return 0;
}
