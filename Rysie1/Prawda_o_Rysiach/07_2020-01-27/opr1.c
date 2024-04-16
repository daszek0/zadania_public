// Jakub Daszkiewicz
// zadanie Jaki to kąt?

#include <stdio.h>

int main()
{
    unsigned short _;
    scanf("%hu", &_);
    if (_ < 90) printf("OSTRY\n");
    else if (_ == 90) printf("PROSTY\n");
    else printf("ROZWARTY\n");
    return 0;
}