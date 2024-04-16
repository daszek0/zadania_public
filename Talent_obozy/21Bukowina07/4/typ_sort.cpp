// Jakub Daszkiewicz
// zadanie Drukarka

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string w[n];
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	sort(w, w + n);
	string cs;
	unsigned cc;
	string a;
	for (int i = 0; i < n; i++)
	{
		cc = 0;
		// sprawdzenie prefiksu który może być taki sam
		while (cc < cs.size() && cc < w[i].size() && cs[cc] == w[i][cc])
		{
			cc++;
		}
		// osiągnęliśmy koniec któregoś lub inny znak, potencjalnie trzeba usunąć
		a.append(cs.size() - cc, '-');
		cs.erase(cc, cs.size() - cc);
		// potencjalnie trzeba dodać
		cs.append(w[i], cc, w[i].size());
		a.append(w[i], cc, w[i].size());
		a.push_back('P');
	}
	cout << a.size() << '\n';
	for (auto i : a)
	{
		cout << i << '\n';
	}
	return 0;
}