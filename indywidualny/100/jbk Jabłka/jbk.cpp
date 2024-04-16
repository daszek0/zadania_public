// Jakub Daszkiewicz
// zadanie Jabłka

#include <cstdio>

using namespace std;

int main()
{
	int n, m, j, r, a = 0, s = 1, e;
	scanf("%d %d %d", &n, &m, &j);
	e = s + m - 1;
	for (int i = 0; i < j; i++)
	{
		scanf("%d", &r);
		if (r < s)
		{
			a += s - r;
			e += r - s;
			s += r - s;
		}
		else if (r > e)
		{
			a += r - e;
			s += r - e;
			e += r - e;
		}
	}
	printf("%d", a);
	return 0;
}