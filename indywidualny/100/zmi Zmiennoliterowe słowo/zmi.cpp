// Jakub Daszkiewicz
// zadanie Zmiennoliterowe słowo

#include <cstdio>

using namespace std;

int main()
{
	int a = 0, l = 1;
	char pc = getchar_unlocked();
	char c = getchar_unlocked();
	while (c != EOF)
	{
		if (c == pc)
		{
			l++;
		}
		else
		{
			a += l - 1;
			l = 1;
		}
		pc = c;
		c = getchar_unlocked();
	}
	printf("%d", a);
	return 0;
}