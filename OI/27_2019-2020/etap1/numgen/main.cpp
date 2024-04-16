#include <stdio.h>

using namespace std;

int main()
{
	while(true)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        for(a; a<b; ++a)
            printf("%d ", a);
        printf("\n");
    }
    return 0;
}
