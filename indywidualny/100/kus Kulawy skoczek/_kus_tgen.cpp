// Jakub Daszkiewicz
// zadanie 

#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	srand(213769420);
	const int N = 1000;
	printf("%d\n", N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", rand() % 1000001);
		printf("\n");
	}
	return 0;
}