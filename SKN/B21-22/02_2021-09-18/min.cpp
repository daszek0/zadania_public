// Jakub Daszkiewicz
// zadanie Konflikt

#include <cstdio>
#include <vector>

using namespace std;

int ni[100001]; // czy był na wejściu i jak
vector<int> g[100001]; // sąsiedztwo
int v[100001]; // odwiedzone
int d[100001]; // głębokość

int main()
{
	int n, m, a, b, s;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		if (i == 0)
		{
			s = a;
		}
		ni[b] = -1;
		if (ni[a] == 0)
		{
			ni[a] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ni[i] == 1)
		{
			s = i;
			break;
		}
	}
	// jeszcze sporo pracy
	return 0;
}