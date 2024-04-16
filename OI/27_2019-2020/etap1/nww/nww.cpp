#include <stdio.h>

using namespace std;

unsigned long long nwd(unsigned long long a, unsigned long long b)
{
	while (a>0 && b>0)
	{
		if (a>b) a%=b;
		else b%=a;
	}
	return a+b;
}

unsigned long long nww(unsigned long long a, unsigned long long b)
{
	return a*b/nwd(a,b);
}

int main()
{
	int z;
	scanf("%d", &z);
	for (int p=0; p<z; ++p)
	{
		unsigned long long m;
		scanf("%llu", &m);
		unsigned long long a, b = m, n, ra = m, rb = m;
		for (b; b>1; --b)
		{
			n = nww(b, b-1);
			if (m%n != 0) continue;
			for (a = b-1; a>1; --a)
			{
				if (m%nww(n, a-1) != 0)
				{
					break;
				}
				else
				{
					n = nww(n, a-1);
				}
			}
			if (n != m) continue;
			if (b <= rb && a <= ra)
			{
				rb = b;
				ra = a;
			}
		}
		if (rb <= ra) printf("NIE\n");
		else printf("%llu %llu\n", ra, rb);
	}
	return 0;
}
