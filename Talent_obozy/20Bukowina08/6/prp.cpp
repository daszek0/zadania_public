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

bool aaaa(pair <int, int> p0, pair <int, int> p1)
{
    return p0.second < p1.second;
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
    map <int, int> dp, dp_;
    // int dp[c+1], dp_[c+1];
    // fill(dp, dp+c+1, 0);
    for (int i=0; i<n; i++)
    {
        dp_ = dp;
        // for (int j=0; j<c+1; j++) dp_[j] = dp[j];
        if (s[i].second > dp[s[i].first]) dp[s[i].first] = s[i].second;
        for (int j=1; j+s[i].first < c+1; j++)
        {
            if (dp_.count(j) == 0) continue;
            if (dp_[j] + s[i].second > dp[j+s[i].first]) dp[j+s[i].first] = dp_[j] + s[i].second;
        }
    }
    // int r = dp[(int)*max_element(dp.begin(), dp.end())];
    printf("%d", (*max_element(dp.begin(), dp.end(), aaaa)).second);
    return 0;
}