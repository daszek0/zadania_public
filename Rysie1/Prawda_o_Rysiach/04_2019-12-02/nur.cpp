// Jakub Daszkiewicz
// zadanie Numer i Wartość Liczby Największej

#include <stdio.h>

using namespace std;

int main()
{
	int n[10], m = -1, ri;
	for (int i=0; i<10; ++i)
	{
		scanf("%d", &n[i]);
	}
	for (int i=0; i<10; ++i)
	{
		if (n[i] > m)
		{
			m = n[i];
			ri = i+1;
		}
	}
	printf("%d %d", ri, m);
	return 0;
}
