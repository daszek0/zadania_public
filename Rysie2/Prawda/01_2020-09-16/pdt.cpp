// Jakub Daszkiewicz
// zadanie Podatki

#include <stdio.h>
#include <algorithm>

using namespace std;

int b[100001];

int main()
{
	int n, t, m = 0;
	long long a = 0;
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &t);
		b[t]++;
		m = max(m, t);
	}
	bool od = true;
	for (int i=m; i>1; i--)
	{
		if (b[i] % 2)
		{
			if (od)
			{
				b[i-1] += b[i]/2+1;
				b[i-2] += b[i]/2;
//				a += b[i] * 3 / 2 + 1;
				a += b[i] / 2 + 1;
				a += b[i] - 1;
			}
			else
			{
				b[i-1] += b[i] / 2;
				b[i-2] += b[i] / 2 + 1;
				a += b[i] / 2;
				a += b[i] + 1;
			}
			od ^= 1;
		}
		else
		{
			b[i-2] += b[i]/2;
			b[i-1] += b[i]/2;
			a += b[i] * 3 / 2;
		}
	}
	if (od && b[1]) a++;
	printf("%lld", a);
	return 0;
}
