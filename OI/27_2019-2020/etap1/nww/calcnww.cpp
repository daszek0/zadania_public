#include <stdio.h>

using namespace std;

int nwd(unsigned long long a, unsigned long long b)
{
        while (a>0 && b>0)
        {
                if (a>b) a%=b;
                else b%=a;
        }
        return a+b;
}

int nww(unsigned long long a, unsigned long long b)
{
        return a*b/nwd(a,b);
}


int main()
{
	int i, a, b, r;
	scanf("%d", &i);
	scanf("%d, %d", &a, &b);
	r = nww(a, b);
	for (i; i>=2; i--)
	{
		int t;
		scanf("%d", &t);
		r = nww(r, t);
	}
	printf("%d\n", r);
	return 0;
}
