// Jakub Daszkiewicz
// zadanie prz generator

#include <cstdio>
#include <cstdlib>

using namespace std;

const int n = 6;
int d[n][n];

int main()
{
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			d[i][j] = (rand() % 40) - 20;
			d[j][i] = -d[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}