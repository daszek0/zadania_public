// Jakub Daszkiewicz
// zadanie Sale wykładowe

#include <stdio.h>

using namespace std;

int input_area()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a == b)
    {
        b = c;
    }
    return a*b;
}

int main()
{
    int a = input_area();
    int b = input_area();
    if (a < b) printf("<");
    else if (a > b) printf(">");
    else printf("=");
    return 0;
}