// Jakub Daszkiewicz
// zadanie Wielki Zjazd Plików

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int n, q, t;
	scanf("%d %d", &n, &q);
	int size[100000], size_sorted[100000];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &size[i]);
	}
	copy(size, size + n, size_sorted);
	sort(size_sorted, size_sorted + n);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &t);
		t--;
		printf("%ld\n", 2 + size + n - lower_bound(size_sorted, size_sorted + n, size[t]));
	}
	return 0;
}