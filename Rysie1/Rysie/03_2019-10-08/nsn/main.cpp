#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n%2 == 0)
        n++;
    else
        n += 2;
    printf("%d", n);
    return 0;
}
