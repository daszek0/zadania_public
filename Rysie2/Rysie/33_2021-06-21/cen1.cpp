// Jakub Daszkiewicz
// zadanie Cena

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int s[100001], c = 2;
	s[0] = 0;
	s[1] = 0;
	fill(s + 2, s + 100001, 1);
	for (int i = 2; i < 100001; i++)
	{
		if (s[i])
		{
			for (int j = i << 1; j < 100001; j += i)
			{
				s[j] = 0;
			}
		}
	}
	vector<int> p;
	while(p.size() < 3000)
	{
		if (s[c])
			p.push_back(c);
		c++;
	}
	char n = getchar_unlocked();
	int a = 0;
	for (int i = 0; n != EOF; i++)
	{
		if (n == '1')
			a += p[i];
		n = getchar_unlocked();
	}
	printf("%d", a);
	return 0;
}