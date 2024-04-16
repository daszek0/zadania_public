// Daszek
// Moons and Umbrellas

#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int t, cj, jc, r, l, i;
	char s[1001];
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		r = 0;
		scanf("%d %d %s", &cj, &jc, s);
		l = strlen(s);
		i = 1;
		while (i < l)
		{
			if (s[i] == 'C')
				if (s[i - 1] == 'J')
					r += jc;
			else if (s[i] == 'J')
				if (s[i - 1] == 'C')
					r += cj;
			else if (s[i] == '?')
			{
				
			}
		}
	}
	return 0;
}