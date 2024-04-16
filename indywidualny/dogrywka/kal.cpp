// Jakub Daszkiewicz
// zadanie KALKULATOR

#include <cstdio>

using namespace std;

int dn;

bool check(long long n)
{
	int d = n % 10;
	dn = 0;
	while (n)
	{
		dn++;
		if (n % 10 != d)
			return false;
		n /= 10;
	}
	return true;
}

int main()
{
	long long n;
	scanf("%lld", &n);
	for (long long i = 1; n * i < __INT64_MAX__; i++)
	{
		if (check(n * i))
		{
			printf("%lld %d\n", (n * i) % 10, dn);
			return 0;
		}
	}
	printf("NIE\n");
	return 0;
}