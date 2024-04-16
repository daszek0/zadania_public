// Jakub Daszkiewicz
// zadanie Kolorowe płytki

#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> r;
    int t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if (!(i && t == r.back()))
            r.push_back(t);
    }
    int dp[r.size()][r.size()];
    for (unsigned i = 0; i < r.size(); i++)
    {
        dp[i][i] = 0;
    }
    for (unsigned i = 1; i < r.size(); i++) // długość
    {
        for (unsigned j = 0; j + i < r.size(); j++) // początek
        {
            if (r[j] == r[j + i])
                dp[j][j + i] = dp[j + 1][j + i - 1] + 1;
            else
                dp[j][j + i] = min(dp[j][j + i - 1], dp[j + 1][j + i]) + 1;
        }
    }
    printf("%d", dp[0][r.size() - 1]);
    return 0;
}