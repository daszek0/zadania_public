#include <stdio.h>

using namespace std;

int main()
{
    int number[10];
    for (int i=0; i<10; i++) scanf("%d", &number[i]);
    for (int i=0; i<10; i++)
    {
        if (number[i]%2 == 1)
            printf("%d\n", number[i]);
    }

    return 0;
}
