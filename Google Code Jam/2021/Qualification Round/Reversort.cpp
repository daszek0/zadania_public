// Daszek
// Reversort

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, c, m;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		int l[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &l[i]);
		}
		c = 0;
		for (int i = 0; i < n - 1; i++)
		{
			m = i;
			for (int j = i; j < n; j++)
			{
				if (l[j] < l[m])
				{
					m = j;
				}
			}
			c += m - i + 1;
			reverse(l + i, l + m + 1);
		}
		printf("Case #%d: %d\n", i, c);
	}
	return 0;
}