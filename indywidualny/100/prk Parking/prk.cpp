// Jakub Daszkiewicz
// zadanie Parking

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int inf = 2147483647;

int x(pair <int, int> p0, pair <int, int> p1)
{
    return abs(p0.first - p1.first) + abs(p0.second - p1.second);
}

int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    vector <pair <int, int>> c[26];
    char t;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            t = getchar_unlocked();
            c[int(t - 'A')].push_back(make_pair(i, j));
        }
        getchar_unlocked();
    }
    int r[26];
    fill(r, r+26, inf);
    for (int i=0; i<26; i++)
    {
        for (int j=0; j<c[i].size(); j++)
        {
            for (int k=j+1; k<c[i].size(); k++)
            {
                r[i] = min(r[i], x(c[i][j], c[i][k]));
            }
        }
    }
    int q;
    scanf("%d", &q);
    for (int i=0; i<q; i++)
    {
        getchar_unlocked();
        t = getchar_unlocked();
        if (r[int(t - 'A')] == inf) printf("BRAK\n");
        else printf("%d\n", r[int(t - 'A')]);
    }
    return 0;
}