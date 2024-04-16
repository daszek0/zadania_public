// Jakub Daszkiewicz
// zadanie Działka ogrodowa

#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

struct coords
{
	int x, y;
};

const int N = 2000; // 70002;

int tree_map_sum[N][N];

int main()
{
	int width, height, number_of_trees;
	scanf("%d %d\n%d", &width, &height, &number_of_trees);
	coords tree_coords;
	for (int i = 0; i < number_of_trees; i++)
	{
		scanf("%d %d", &tree_coords.x, &tree_coords.y);
		tree_coords.x += 1000;
		tree_coords.y += 1000;
		tree_map_sum[tree_coords.x][tree_coords.y] = 1;
	}
	for (int x = 1; x < N; x++)
	{
		for (int y = 1; y < N; y++)
		{
			tree_map_sum[x][y] += tree_map_sum[x - 1][y] + tree_map_sum[x][y - 1] - tree_map_sum[x - 1][y - 1];
		}
	}
	int answer = 0;
	for (int x = 1; x < N - width; x++)
	{
		for (int y = 1; y < N - height; y++)
		{
			answer = max(answer, tree_map_sum[x + width][y + height] - tree_map_sum[x][y + height] - tree_map_sum[x - width][y] + tree_map_sum[x][y]);
		}
	}
	printf("%d", answer);
	return 0;
}