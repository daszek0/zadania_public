// Jakub Daszkiewicz
// zadanie Zawody

// test 1: 4 3 26 2 39 3 45 1 56 2 => 2

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int k, n;
    scanf("%d%d", &k, &n);
    int t[k], p[k];
    for (int i=0; i<k; i++)
    {
        scanf("%d%d", &t[i], &p[i]);
    }
    int tl[k][n], s[k];
    vector<int> times;
    // int b[1000000001] = {0};
    for (int i=0; i<k; i++)
    {
        tl[i][0] = t[i];
        s[i] = t[i];
        times.push_back(s[i]);
        // b[s[i]]++;
        for (int j=1; j<n; j++)
        {
            if (j == p[i])
            {
                tl[i][j] = t[i];
            }
            else
            {
                tl[i][j] = tl[i][j-1]+1;
            }
            s[i] += tl[i][j];
            times.push_back(s[i]);
            // b[s[i]]++;
        }
    }
    sort(times.begin(), times.end());
    int m = 1, count = 1;
    for(int i=1; i<times.size(); i++)
    {
        if (times[i] == times[i-1]) count++;
        else count = 1;
        m = max(count, m);
    }
    printf("%d", m);
    return 0;
}