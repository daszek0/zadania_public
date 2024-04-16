#include <stdio.h>

using namespace std;

int main()
{
    int n, w = 0, b = 0;
    char t;
    scanf("%d", &n); getchar_unlocked();
    for (int i=0; i<n; i++)
    {
        t = getchar_unlocked(); // scanf("%c", &t);
        if (t == 'B') ++w;
        else if (t == 'C') ++b;
    }
    for (int i=0; i<w; i++)
        printf("B");
    for (int i=0; i<b; i++)
        printf("C");
    return 0;
}