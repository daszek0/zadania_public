// Jakub Daszkiewicz
// zadanie Park trampolin

#include <cstdio>
#include <algorithm>

using namespace std;

long long M = 1e9 + 7;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	long long w[n][m], ah[n][m], av[n][m], t, ch = 0, cv[m];
	fill(&w[0][0], &w[n - 1][m - 1] + 1, 0);
	w[0][0] = 1;
	fill(&ah[0][0], &ah[n - 1][m - 1] + 1, 0);
	fill(&av[0][0], &av[n - 1][m - 1] + 1, 0);
	fill(cv, cv + m, 0);
	for (int i = 0; i < n; i++)
	{
		ch = 0;
		for (int j = 0; j < m; j++)
		{
			scanf("%lld", &t);
			ch += ah[i][j];
			if (ch >= M)
			{
				ch -= M;
			}
			cv[j] += av[i][j];
			if (cv[j] >= M)
			{
				cv[j] -= M;
			}
			w[i][j] += ch;
			if (w[i][j] >= M)
			{
				w[i][j] -= M;
			}
			w[i][j] += cv[j];
			if (w[i][j] >= M)
			{
				w[i][j] -= M;
			}
			if (i + t + 1 < n)
			{
				av[i + t + 1][j] += M;
				av[i + t + 1][j] -= w[i][j];
				if (av[i + t + 1][j] >= M)
				{
					av[i + t + 1][j] -= M;
				}
			}
			if (j + t + 1 < m)
			{
				ah[i][j + t + 1] += M;
				ah[i][j + t + 1] -= w[i][j];
				if (ah[i][j + t + 1] >= M)
				{
					ah[i][j + t + 1] -= M;
				}
			}
			ch += w[i][j];
			if (ch >= M)
			{
				ch -= M;
			}
			cv[j] += w[i][j];
			if (cv[j] >= M)
			{
				cv[j] -= M;
			}
		}
	}
	printf("%lld", w[n - 1][m - 1]);
	return 0;
}