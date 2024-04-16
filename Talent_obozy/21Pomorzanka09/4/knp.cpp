// Jakub Daszkiewicz
// zadanie Kanapka

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> z_alg(vector<int> s)
{
	vector<int> z(s.size());
	z[0] = 0;
	int f = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (f + z[f] > z[i - f] + i)
		{
			z[i] = z[i - f];
		}
		else
		{
			z[i] = max(0, f + z[f] - i);
			f = i;
			while (s[i + z[i]] == s[z[i]])
			{
				z[i]++;
			}
		}
	}
	return z;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> s(n);
	for (auto &&i : s)
	{
		scanf("%d", &i);
	}
	vector<int> z = z_alg(s);
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		if (z[i] < i)
		{
			a = max(a, z[i]);
		}
	}
	printf("%d", a);
	return 0;
}