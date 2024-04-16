// Jakub Daszkiewicz
// zadanie Sklep akwarystyczny

#include <cstdio>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long f[1000001], ts[1000001];
int n, q, a, b, c;
vector<unsigned long long> s;

int main()
{
	mt19937 mt(694202137);
	for (int i = 0; i <= 1000000; i++)
	{
		f[i] = uniform_int_distribution<unsigned long long>(1, (1ULL << 63) - 1)(mt);
	}
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		a--, b--, c--;
		ts[a] += f[c];
		ts[b + 1] -= f[c];
	}
	s.push_back(ts[0]);
	for (int i = 1; i < n; i++)
	{
		ts[i] += ts[i - 1];
		s.push_back(ts[i]);
	}
	sort(s.begin(), s.end());
	printf("%lu", unique(s.begin(), s.end()) - s.begin());
	return 0;
}