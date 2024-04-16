// Jakub Daszkiewicz
// zadanie Koleje

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1 << 16; // 65536
int tree[N << 1][2];
// tfu drzewo rekurencyjnie 🤢🤮

void push(int n)
{
	int a = tree[n][1];
	tree[(n << 1)][0] += a;
	tree[(n << 1)][1] += a;
	tree[(n << 1) + 1][0] += a;
	tree[(n << 1) + 1][1] += a;
	tree[n][1] = 0;
}

void tree_add(int n, int b, int e, int x, int y, int v)
{
	if (e < x || b > y)
		return;
	if (b >= x && e <= y)
	{
		tree[n][0] += v;
		tree[n][1] += v;
		return;
	}
	// if (n < N)
	// {
		push(n);
		tree_add((n << 1), b, ((b + e) >> 1), x, y, v);
		tree_add((n << 1) + 1, ((b + e) >> 1) + 1, e, x, y, v);
		tree[n][0] = max(tree[(n << 1)][0], tree[(n << 1) + 1][0]);
	// }
}

int tree_max(int n, int b, int e, int x, int y)
{
	int r = 0;
	if (e < x || b > y)
		return 0;
	if (b >= x && e <= y)
	{
		// r = max(r, tree[n][0]);
		return tree[n][0];
	}
	// if (n < N)
	// {
		push(n);
		r = max(r, tree_max((n << 1), b, ((b + e) >> 1), x, y));
		r = max(r, tree_max((n << 1) + 1, ((b + e) >> 1) + 1, e, x, y));
	// }
	return r;
}

int main()
{
	int n, m, z, p, k, l;
	scanf("%d %d %d", &n, &m, &z);
	for (int i = 0; i < z; i++)
	{
		scanf("%d %d %d", &p, &k, &l);
		k--;
		if (tree_max(1, 1, N, p, k) + l > m)
			printf("N\n");
		else
		{
			printf("T\n");
			tree_add(1, 1, N, p, k, l);
		}
	}
	return 0;
}