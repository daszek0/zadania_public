// Jakub Daszkiewicz
// zadanie Potęga

#include <iostream>

using namespace std;

int main()
{
	string N;
	cin >> N;
	int n = 0;
	if (N.length() == 1 && N[0] == '0')
	{
		printf("1\n");
	}
	else
	{
		n += (int)(N[N.length()-1]-'0');
		if (N.length() > 1) n += (int)(N[N.length()-2]-'0') * 10;
		switch(n % 4)
		{
			case 1: printf("2\n"); break;
			case 2: printf("4\n"); break;
			case 3: printf("8\n"); break;
			case 0: printf("6\n"); break;
		}
	}
	return 0;
}
