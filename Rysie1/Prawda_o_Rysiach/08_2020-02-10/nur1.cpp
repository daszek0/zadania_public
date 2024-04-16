// Jakub Daszkiewicz
// zadanie Numer i wartość liczby największej

#include <stdio.h>

using namespace std;

int main()
{
	int max = 0, max_i = 0, t;
	for (int i=1; i<=10; i++)
	{
		scanf("%d", &t);
		if (t > max)
		{
			max = t;
			max_i = i;
		}
	}
	printf("%d %d\n", max_i, max);
	return 0;
}
