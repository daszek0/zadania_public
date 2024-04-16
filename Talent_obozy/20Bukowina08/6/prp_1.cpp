// Jakub Daszkiewicz
// zadanie Problem plecaka

#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair <int, int> p0, pair <int, int> p1)
{
    if (p0.second == p1.second)
    {
        return p0.first < p1.first;
    }
    return p0.second > p1.second;
}

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    pair <int, int> s[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &s[i].first, &s[i].second);
    }
    sort(s, s+n, comp);
    int dp[4];
    for (int i=0; i<n; i++)
    {
        dp_ = dp;
        if (s[i].second > dp[s[i].first]) dp[s[i].first] = s[i].second;
        for (int j=1; j+s[i].first < c+1; j++)
        {
            if (dp_.count(j) == 0) continue;
            if (dp_[j] + s[i].second > dp[j+s[i].first]) dp[j+s[i].first] = dp_[j] + s[i].second;
        }
    }
    printf("%d", (*max_element(dp.begin(), dp.end(), aaaa)).second);
    return 0;
}