// Jakub Daszkiewicz
// zadanie Liczba przystanków

#include <stdio.h>

using namespace std;

int main()
{
    int r, w, s, h;
    scanf("%d %d %d %d", &r, &h, &w, &s);
    printf("%d", (60*h+w-s)/r);
    return 0;
}