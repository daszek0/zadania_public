#include <stdio.h>

using namespace std;

int main()
{
    int angle;
    scanf("%d", &angle);
    if (angle < 90)
        printf("OSTRY");
    else if (angle == 90)
        printf("PROSTY");
    else if (angle > 90)
        printf("ROZWARTY");
    return 0;
}
