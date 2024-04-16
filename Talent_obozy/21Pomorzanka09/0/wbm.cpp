// Jakub Daszkiewicz
// zadanie Wielka Biesiada w Misiowie

#include <cstdio>

using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	n++;
	printf("%lld", (n % 2) ? ((n >> 1) * 3 + ((n >> 1) + 1) * 4) : ((n >> 1) * 3 + (n << 1)));
	return 0;
}