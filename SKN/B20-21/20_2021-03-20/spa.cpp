// Jakub Daszkiewicz
// zadanie Spacer

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int t[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &t[i][j]);
	for (int i = n - 2; i >= 0; i--)
		t[i][m - 1] += t[i + 1][m - 1];
	for (int i = m - 2; i >= 0; i--)
		t[n - 1][i] += t[n - 1][i + 1];
	for (int i = n - 2; i >= 0; i--)
		for (int j = m - 2; j >= 0; j--)
		{
			if ((i & 1) == (j & 1))
				t[i][j] += max(t[i + 1][j], t[i][j + 1]);
			else
				t[i][j] += min(t[i + 1][j], t[i][j + 1]);
		}
	printf("%d", t[0][0]);
	return 0;
}