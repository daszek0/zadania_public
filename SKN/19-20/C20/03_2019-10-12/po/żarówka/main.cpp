#include <stdio.h>

using namespace std;

int main()
{
	int a;
	unsigned long long r = 1;
	unsigned long long x = 1;
	scanf("%d", &a);
	for (int i=1; i<a; ++i)
    {
        x *= 4;
        x %= 500000009;
        r = (r + x)%500000009;
    }
    printf("%llu", r);
    return 0;
}
