// Jakub Daszkiewicz
// zadanie Równy podział

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int dp[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dp[i]);
		if (i > 0)
		{
			dp[i] += dp[i - 1];
		}
	}
	int m = 1;
	int c = abs(dp[n - 1] - dp[1] - dp[1]);
	for (int i = 2; i < n - 1; i++)
	{
		if (abs(dp[n - 1] - dp[i] - dp[i]) < c)
		{
			m = i;
			c = abs(dp[n - 1] - dp[i] - dp[i]);
		}
	}
	int m1 = 0;
	c = abs(dp[m] - dp[0] - dp[0]);
	for (int i = 1; i < m; i++)
	{
		if (abs(dp[m] - dp[i] - dp[i]) < c)
		{
			m1 = i;
			c = abs(dp[m] - dp[i] - dp[i]);
		}
	}
	int m2 = m + 1;
	c = abs(dp[n - 1] - dp[m + 1] - dp[m + 1] + dp[m]);
	for (int i = m + 2; i < n; i++)
	{
		if (abs(dp[n - 1] - dp[i] - dp[i] + dp[m]) < c)
		{
			m2 = i;
			c = abs(dp[n - 1] - dp[i] - dp[i] + dp[m]);
		}
	}
	m = m1 + 1;
	c = abs(dp[m2] - dp[m1 + 1] - dp[m1 + 1] + dp[m1]);
	for (int i = m1 + 2; i < m2; i++)
	{
		if (abs(dp[m2] - dp[i] - dp[i] + dp[m1]) < c)
		{
			m = i;
			c = abs(dp[m2] - dp[i] - dp[i] + dp[m1]);
		}
	}
	int s[4];
	s[0] = dp[m1];
	s[1] = dp[m] - dp[m1];
	s[2] = dp[m2] - dp[m];
	s[3] = dp[n - 1] - dp[m2];
	printf("%d", *max_element(s, s + 4) - *min_element(s, s + 4));
	return 0;
}