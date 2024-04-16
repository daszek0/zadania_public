// Jakub Daszkiewicz
// zadanie Park trampolin

#include <cstdio>

using namespace std;

const long long M = 1000000007;
long long w[1001][1001];

// tablica drzew przedział punkt iteracyjnie

int main()
{
	int n, m, p;
	scanf("%d %d", &n, &m);
	w[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &p);
			for (int k = i + 1; k <= i + p && k < n; k++) // zamienić na drzewo
			{
				w[k][j] += w[i][j]; // trzeba odczytać z drzew i zapisać do zmiennej
				w[k][j] %= M;
			}
			for (int k = j + 1; k <= j + p && k < m; k++) // zamienić na drzewo
			{
				w[i][k] += w[i][j];
				w[i][k] %= M;
			}
		}
	}
	printf("%lld", w[n - 1][m - 1]);
	return 0;
}