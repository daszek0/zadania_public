// Jakub Daszkiewicz
// zadanie Bankomaty

#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 64;

int main()
{
	int n;
	scanf("%d", &n);
	bitset<N> b;
	unsigned long long t;
	vector<int> o;
	for (int i = 0; i < n; i++)
	{
		scanf("%llu", &t);
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