// Jakub Daszkiewicz
// zadanie Maksymalna suma

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n, m, t;
    scanf("%d", &n);
    vector <int> b[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &m);
        for (int ii=0; ii<m; ii++)
        {
            scanf("%d", &t);
            b[i].push_back(t);
        }
        sort(b[i].begin(), b[i].end(), greater<int>());
    }
    int s[1001], so[1001];
    fill(s, s+1001, 0);
    // fill(so, so+1001, 0);
    for (int i=n-1; i>=0; i--)
    {
        for (int ii=0; ii<1001; ii++)
        {
            so[ii] = s[ii];
        }
        for (int ii=0; ii<b[i].size(); ii++)
        {
            for (int iii=b[i][ii]; iii>0; iii--)
            {
                if (so[b[i][ii]] + b[i][ii] > s[iii]) s[iii] = so[b[i][ii]] + b[i][ii];
            }
        }
    }
    printf("%d", s[1]);
    return 0;
}