// Jakub Daszkiewicz
// zadanie Dwa-trzy liczby

#include <cstdio>

using namespace std;

int main()
{
	long long x, y, a = 0;
	scanf("%lld %lld", &x, &y);
	for (long long i = 1; i <= y; i *= 2)
	{
		for (long long j = i; j <= y; j *= 3)
		{
			if (j >= x && j != 1) a++;
		}
	}
	printf("%lld", a);
	return 0;
}