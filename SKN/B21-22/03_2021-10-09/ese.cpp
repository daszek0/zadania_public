// Jakub Daszkiewicz
// zadanie Esej

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int L = 4;

struct D
{
	int l1[L] = {0};
	int l2[L] = {0};
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	D c[m + 2][m + 2]; // 0 i m+1 to wartości brzegowe
	for (int i = 0; i < n; i++)
	{
		c[0][m + 1].l1[s1[i] - 'a']++;
	}
	for (int i = 0; i < m; i++)
	{
		c[0][m + 1].l2[s2[i] - 'a']++;
	}
	vector<int> a = {m};
	for (int i = 1; i < m + 1; i++)
	{
		c[i][m + 1] = c[i - 1][m + 1];
		// c[i][j] = c[i - 1][j + 1];
		if (c[i][m + 1].l1[s2[i - 1] - 'a'] == 0 || c[i][m + 1].l2[s2[i - 1] - 'a'] == 0)
		{
			a.push_back(m - i + 1);
			// a.push_back(0);
			// for (int k = 0; k < L; k++)
			// {
			// 	a.back() += c[i][m + 1].l2[k];
			// }
			break;
		}
		c[i][m + 1].l1[s2[i - 1] - 'a']--;
		c[i][m + 1].l2[s2[i - 1] - 'a']--;
		for (int j = m; j > i; j--)
		{
			c[i][j] = c[i][j + 1];
			if (c[i][j].l1[s2[j - 1] - 'a'] == 0 || c[i][j].l2[s2[j - 1] - 'a'] == 0)
			{
				a.push_back(j - i);
				// a.push_back(0);
				// for (int k = 0; k < L; k++)
				// {
				// 	a.back() += c[i][j].l2[k];
				// }
				break;
			}
			c[i][j].l1[s2[j - 1] - 'a']--;
			c[i][j].l2[s2[j - 1] - 'a']--;
		}
	}
	cout << *min_element(a.begin(), a.end());
	return 0;
}