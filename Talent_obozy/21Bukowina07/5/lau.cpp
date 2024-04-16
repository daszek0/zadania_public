// Jakub Daszkiewicz
// zadanie Laurka

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q, a, b, c;
	string l;
	cin >> n >> q >> l;
	for (int i = 0; i < q; i++)
	{
		cin >> a >> b >> c;
		a--;
		if (c)
		{
			sort(&l[a], &l[b]);
		}
		else
		{
			sort(&l[a], &l[b], greater<char>());
		}
	}
	cout << l << '\n';
	return 0;
}