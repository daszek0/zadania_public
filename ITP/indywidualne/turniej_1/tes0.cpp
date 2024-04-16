#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        putchar_unlocked('*');
    }
    return 0;
}