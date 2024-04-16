// Jakub Daszkiewicz
// zadanie Prawie równoważne słowa

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> z(string s)
{
	vector<int> z(s.length());
	z[0] = 0;
	int f = 0;
	for (int i = 1; i < s.length(); i++)
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
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	string w, p, f, b;
	cin >> w >> p;
	w += w;
	f = p + "#" + w;
	reverse(p.begin(), p.end());
	reverse(w.begin(), w.end());
	b = p + "#" + w;
	vector<int> zf, zb, a;
	zf = z(f);
	zb = z(b);
	for (int i = n + 1; i < n + 1 + n; i++)
	{
		if (zf[i] + zb[zb.size() - (i - 1)] == n - 1)
		{
			a.push_back(i - n - 1);
		}
	}
	cout << (a.size() ? "TAK" : "NIE") << '\n';
	for (auto i : a)
	{
		cout << i << ' ';
	}
	return 0;
}