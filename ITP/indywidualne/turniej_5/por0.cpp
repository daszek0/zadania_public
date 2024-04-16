// Jakub Daszkiewicz
// zadanie Pora dnia

#include <stdio.h>

using namespace std;

int main()
{
    int h, m;
    scanf("%d:%d", &h, &m);
    if (h < 6 || h >= 22) printf("noc");
    else if (h < 12) printf("rano");
    else if (h < 14) printf("poludnie");
    else if (h < 18) printf("popoludnie");
    else if (h < 22) printf("wieczor");
    return 0;
}