// Jakub Daszkiewicz
// zadanie Kuba

#include <cstdio>
#include <vector>

using namespace std;

struct node
{
	int n[4], e;
};

const node e = {{0, 0, 0, 0}, 0};

vector<node> g /* [1000001] */;

int ltn(char l)
{
	switch (l)
	{
	case 'K':
		return 0;
		break;
	case 'U':
		return 1;
		break;
	case 'B':
		return 2;
		break;
	case 'A':
		return 3;
		break;
	default:
		break;
	}
	return -1;
}

int main()
{
	int n;
	scanf("%d\n", &n);
	g.push_back(e);
	g.push_back(e);
	char c;
	int cn, l, we[n];
	for (int i = 0; i < n; i++)
	{
		cn = 1;
		c = getchar_unlocked();
		while (c >= 'A' && c <= 'Z')
		{
			l = ltn(c);
			if (g[cn].n[l] == 0)
			{
				g[cn].n[l] = g.size();
				g.push_back(e);
			}
			cn = g[cn].n[l];
			g[cn].e++;
			c = getchar_unlocked();
		}
		we[i] = cn;
		// printf("%d\n", g[cn].e);
		// g[cn].e++;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", g[we[i]].e - 1);
	}
	return 0;
}