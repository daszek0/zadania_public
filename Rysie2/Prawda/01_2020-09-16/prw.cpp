// Jakub Daszkiewicz
// zadanie Prostokątne wyspy

#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int c[200001]; // tu powinno być drzewo przedziałowe

struct rect
{
	int x, y, h, w;
};

bool rect_x(rect r0, rect r1)
{
	return r0.x < r1.x;
}

bool rect_y(rect r0, rect r1)
{
	return r0.y < r1.y;
}

int main()
{
	int n;
	scanf("%d", &n);
	rect inp[n];
	for (int i=0; i<n; i++)
	{
		scanf("%d %d %d %d", &inp[i].x, &inp[i].y, &inp[i].w, &inp[i].h);
	}
	sort(inp, inp+n, rect_x);
	map <int, int> mx;
	pair <int, int> tc[n*2];
	for (int i=0; i<n; i++)
	{
		tc[i*2] = make_pair(inp[i].x, 1);
		tc[i*2+1] = make_pair(inp[i].x + inp[i].w, -1);
	}
	sort(tc, tc+2*n);
	sort(inp, inp+n, rect_y);
	map <int, int> my;
	for (int i=0; i<n; i++)
	{
		mx[inp[i].x] = i;
		my[inp[i].y] = i;
	}
	for (int i=0; i<n*2; i++)
	{
		for (int i=mx[tc[i]]; i<
	}
	return 0;
}
