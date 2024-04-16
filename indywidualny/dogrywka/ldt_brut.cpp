// Jakub Daszkiewicz
// zadanie Dwa-trzy liczby

#include <cstdio>

using namespace std;

int main()
{
	long long x, y, a = 0, c;
	scanf("%lld %lld", &x, &y);
	for (long long i = x; i <= y; i++)
	{
		if (i == 1)
			continue;
		c = i;
		while (c % 2 == 0)
			c /= 2;
		while (c % 3 == 0)
			c /= 3;
		if (c == 1)
			a++;
	}
	printf("%lld", a);
	return 0;
}