// analiza charów

#include <stdio.h>

using namespace std;

int main()
{
    char c;
    while (c != -1)
    {
        c = getchar_unlocked();
        printf("%d ", (int)c);
    }
    return 0;
}