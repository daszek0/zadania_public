// Jakub Daszkiewicz
// zadanie Słoiki

#include <stdio.h>
#include <algorithm>

using namespace std;

int tree[1 << 19][3]; // trzymamy aktualna wartosc i ta do przepchniecia
int wynik;

void push(int w)
{
    if (tree[w][2])
    {
        swap(tree[w*2][0], tree[w*2][1]);
        tree[w*2][2] ^= 1;
        swap(tree[w*2+1][0], tree[w*2+1][1]);
        tree[w*2+1][2] ^= 1;
        tree[w][2] = 0;
    }
}

void change(int w, int p, int k, int x, int y)
{
	if (k<x || p>y) return;
	if (p>=x && k<=y)
	{
        swap(tree[w][0], tree[w][1]);
		tree[w][2] ^= 1;
		return;
	}
	push(w); //przed schodzeniem nizej uaktualniamy wynik w synach
	change(w*2,p,(p+k)/2,x,y);
	change(w*2+1,(p+k)/2+1,k,x,y);
	tree[w][0] = tree[w*2][0] + tree[w*2+1][0]; //uaktualniamy informacje w danym wierzcholku
	tree[w][1] = tree[w*2][1] + tree[w*2+1][1]; //uaktualniamy informacje w danym wierzcholku
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int s = 0;
    int t;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &t);
        s += t;
        tree[(1 << 18) + i - 1][s % 2]++;
    }
    for (int i=(1 << 18) - 1; i>0; i--)
    {
        tree[i][0] = tree[i << 1][0] + tree[(i << 1) + 1][0];
        tree[i][1] = tree[i << 1][1] + tree[(i << 1) + 1][1];
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d", &t);
        change(1, 1, 1 << 18, t, n);
        printf("%lld\n", ((long long)tree[1][0] * (long long)(tree[1][0] + 1) + (long long)tree[1][1] * (long long)(tree[1][1] - 1)) >> 1);
    }
    return 0;
}