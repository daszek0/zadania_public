// Jakub Daszkiewicz
// zadanie Do góry i do dołu

#include <cstdio>
#include <climits>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int s[n], mv = 0, mp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
		if (s[i] > mv)
		{
			mv = s[i];
			mp = i;
		}
	}
	int a = 0, d = 0, m;
	while (true)
	{
		m = INT_MAX;
		for (int i = 0; i < mp; i++)
		{
			if (s[i] < m)
			{
				m = s[i];
				d = i;
			}
		}
		if (m == INT_MAX)
			break;
		a += d;
		s[d] = INT_MAX;
		a++;
	}
	d = 0;
	while (true)
	{
		m = INT_MAX;
		for (int i = n - 1; i > mp; i--)
		{
			if (s[i] < m)
			{
				m = s[i];
				d = n - 1 - i;
			}
		}
		if (m == INT_MAX)
			break;
		a += d;
		s[d] = INT_MAX;
		a++;
	}
	printf("%d", a);
	return 0;
}