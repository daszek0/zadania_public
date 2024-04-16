// Jakub Daszkiewicz
// zadanie Sklep akwarystyczny

#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int n, q, a, b, c;
	scanf("%d %d", &n, &q);
	multiset<int> akwarium[n];
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		for (int j = a; j <= b; j++)
		{
			akwarium[j].insert(c);
		}
	}
	set<multiset<int>> typ;
	typ.insert(akwarium, akwarium + n);
	printf("%u", typ.size());
	return 0;
}