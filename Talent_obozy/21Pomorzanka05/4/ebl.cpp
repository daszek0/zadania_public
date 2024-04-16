// Jakub Daszkiewicz
// zadanie Elektryk Błażej

#include <cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int h[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
	}
	int i = 0, a = 1, np = 1;
	double t;
	while (i < n - 1)
	{
		t = double(-1000000001);
		for (int j = i + 1; j < n; j++)
		{
			if (double(h[j] - h[i]) / double(j - i) > t)
			{
				t = double(h[j] - h[i]) / double(j - i);
				np = j;
			}
		}
		i = np;
		a++;
	}
	printf("%d", a);
	return 0;
}