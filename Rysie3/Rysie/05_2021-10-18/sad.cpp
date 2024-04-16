// Jakub Daszkiewicz
// zadanie Sad

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	pair<long long, long long> n[3];
	for (int i = 0; i < 3; i++)
		scanf("%lld %lld", &n[i].first, &n[i].second);
	long long P2 = abs((n[1].first - n[0].first) * (n[2].second - n[0].second) - (n[2].first - n[0].first) * (n[1].second - n[0].second));
	long long op = __gcd(abs(n[1].first - n[0].first), abs(n[1].second - n[0].second)) + __gcd(abs(n[2].first - n[1].first), abs(n[2].second - n[1].second)) + __gcd(abs(n[0].first - n[2].first), abs(n[0].second - n[2].second));
	printf("%lld", (P2 - op) / 2 + 1);
	return 0;
}