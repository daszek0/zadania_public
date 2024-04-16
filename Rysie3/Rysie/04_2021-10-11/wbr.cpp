// Jakub Daszkiewicz
// zadanie Wyścigi robotów

#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int t[2][n + 2], d[2][n + 2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			scanf("%d", &t[i][j]);
		}
	}
	deque<pair<int, int>> q;
	fill(&d[0][0], &d[1][n + 1] + 1, __INT_MAX__);
	d[0][0] = 0;
	d[1][0] = 0;
	q.push_back(make_pair(0, 0));
	q.push_back(make_pair(1, 0));
	pair<int, int> c;
	while (!q.empty())
	{
		c = q.front();
		q.pop_front();
		// taka dijkstra że to działa i kurwa ten
		// 0 ^ 1 == 1
		// 1 ^ 1 == 0
		// i kurwa ten
		// idziemy do końca zapisując na d
	}

	return 0;
}