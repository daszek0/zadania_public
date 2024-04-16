// Jakub Daszkiewicz
// zadanie Ile zer na końcu

#include <cstdio>

using namespace std;

int main()
{
	int n, a = 0;
	scanf("%d", &n);
	for (int i = n; i >= 0; i--)
	{
		a += i / 5;
	}
	printf("%d", a / 2);
	return 0;
}