// Jakub Daszkiewicz
// zadanie Kulawy skoczek

#include <cstdio>
#include <algorithm>

using namespace std;

int r[1001][1001], dp[1001][1001];

int main()
{
	int n, x, y;
	scanf("%d", &n);
	for (x = 0; x < n; x++) // x rośnie w dół
	{
		for (y = 0; y < n; y++) // y rośnie w dół
		{
			scanf("%d", &r[x][y]); // liczba malin w polu
			dp[x][y] = -1; // nie da się dostać
		}
	}
	dp[0][0] = 0; // na początku mam 0
	for (int i = 0; i < (n << 1); i++)
	{
		x = i;
		y = 0;
		while (x >= 0)
		{
			if (x < n && y < n && dp[x][y] >= 0) // sprawdzam czy nie wychodzę poza planszę i czy w ogóle można się tu dostać
			{
				dp[x][y] += r[x][y]; // dodaję maliny z obecnego pola
				if (x - 1 >= 0 && y + 2 < n) // sprawdzam czy nie wychodzę poza planszę
				{
					dp[x - 1][y + 2] = max(dp[x][y], dp[x - 1][y + 2]); // "idę" lub zostawiam "ścieżkę" już wskazaną wcześniej
				}
				if (x + 1 < n && y + 2 < n) // sprawdzam czy nie wychodzę poza planszę
				{
					dp[x + 1][y + 2] = max(dp[x][y], dp[x + 1][y + 2]);
				}
				if (x + 2 < n && y + 1 < n) // sprawdzam czy nie wychodzę poza planszę
				{
					dp[x + 2][y + 1] = max(dp[x][y], dp[x + 2][y + 1]);
				}
				if (x + 2 < n && y - 1 >= 0) // sprawdzam czy nie wychodzę poza planszę
				{
					dp[x + 2][y - 1] = max(dp[x][y], dp[x + 2][y - 1]);
				}
			}
			x--; // idziemy w prawo do góry
			y++;
		}
	}
	printf("%d", dp[n - 1][n - 1]);
	return 0;
}