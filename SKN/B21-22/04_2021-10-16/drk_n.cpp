// Jakub Daszkiewicz
// zadanie Drzewo rzędu K

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, q;
	long long a, b, ans;
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%lld %lld", &a, &b);
		if (k == 1)
		{
			ans = abs(a - b);
		}
		else
		{
			ans = 0;
			while (a != b)
			{
				while (a > b)
				{
					a += k - 2;
					a /= k;
					ans++;
				}
				while (b > a)
				{
					b += k - 2;
					b /= k;
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}