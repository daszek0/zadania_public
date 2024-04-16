// Jakub Daszkiewicz
// zadanie Bankomaty

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

typedef unsigned __int128 uint128_t; // w dupę można se wsadzić int128

const int N = 128;

int main()
{
	int n;
	cin >> n;
	bitset<N> b;
	uint128_t t;
	vector<int> o;
	for (int i = 0; i < n; i++)
	{
		// cin >> t;
		t = 7;
		b = t;
		// dodawanie
		o.clear();
		o.push_back(-1);
		for (int j = 0; j < N; j++)
		{
			if (b[j])
			{
				if (j & 1)
				{
					if (o.back() == j)
					{
						o.pop_back();
					}
					else
					{
						o.push_back(j);
						o.push_back(j + 1);
					}
				}
				else
				{
					if (o.back() == j)
					{
						o.pop_back();
						o.push_back(j + 1);
						o.push_back(j + 2);
					}
					else
					{
						o.push_back(j);
					}
				}
			}
		}
		sort(o.begin(), o.end(), greater<int>());
		for (auto j : o)
		{
			if (j != -1)
				printf("%d ", j);
		}
		printf("\n");
		// odejmowanie
		o.clear();
		o.push_back(-1);
		for (int j = 0; j < N; j++)
		{
			if (b[j])
			{
				if (j & 1)
				{
					if (o.back() == j)
					{
						o.pop_back();
						o.push_back(j + 2);
						o.push_back(j + 1);
					}
					else
					{
						o.push_back(j);
					}
				}
				else
				{
					if (o.back() == j)
					{
						o.pop_back();
					}
					else
					{
						o.push_back(j);
						o.push_back(j + 1);
					}
				}
			}
		}
		sort(o.begin(), o.end(), greater<int>());
		for (auto j : o)
		{
			if (j != -1)
				printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}