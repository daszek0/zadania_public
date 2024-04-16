// Jakub Daszkiewicz
// zadanie Literki Rosnaco

#include <stdio.h>

using namespace std;

int main()
{
	char a, b;
	scanf("%c %c", &a, &b);
	while (a <= b)
	{
		printf("%c", a);
		a++;
	}
	return 0;
}
