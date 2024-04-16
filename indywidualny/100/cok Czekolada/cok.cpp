// Jakub Daszkiewicz
// zadanie Czekolada

#include <cstdio>

using namespace std;

int main()
{
	int n, m, a = 0;
	scanf("%d %d", &n, &m);
	while (n > 0 && m > 0)
	{
		if (n > m)
		{
			n -= m;
		}
		else
		{
			m -= n;
		}
		a++;
	}
	printf("%d", a);
	return 0;
}