// Jakub Daszkiewicz
// zadanie tra generator

#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int n = rand() % 1000 + 1;
	int m = rand() % 1000 + 1;
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", rand());
		}
	}
	return 0;
}