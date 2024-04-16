// Jakub Daszkiewicz
// zadanie Kalin

#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

int main()
{
	int n;
	scanf("%d\n", &n);
	long long dp[n + 1], lr[26];
	dp[0] = 1;
	fill(lr, lr + 26, 0);
	char c = getchar_unlocked();
	dp[1] = 2;
	lr[c - 'a'] = 1;
	for (int i = 2; i <= n; i++)
	{
		c = getchar_unlocked();
		dp[i] = ((dp[i - 1] << 1) - lr[c - 'a'] + mod) % mod;
		lr[c - 'a'] = dp[i - 1];
	}
	printf("%lld", dp[n]);
	return 0;
}