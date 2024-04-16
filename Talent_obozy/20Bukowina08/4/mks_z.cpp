// Jakub Daszkiewicz
// zadanie Maksymalna suma

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void fastinput(int *n)
{
    int r = 0;
    char c;
    c = getchar_unlocked();
    while (c < '0' || c > '9')
    {
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9')
    {
        r = (r << 3) + (r << 1);
        r += c - '0';
        c = getchar_unlocked();
    }
    *n = r;
}

int main()
{
    int n, m, t;
    fastinput(&n);// scanf("%d", &n);
    vector <int> b[n];
    for (int i=0; i<n; i++)
    {
        fastinput(&m);// scanf("%d", &m);
        for (int ii=0; ii<m; ii++)
        {
            fastinput(&t);// scanf("%d", &t);
            b[i].push_back(t);
        }
        sort(b[i].begin(), b[i].end(), greater<int>());
    }
    int s[1001], so[1001];
    fill(s, s+1001, 0);
    // fill(so, so+1001, 0);
    for (int i=n-1; i>=0; i--)
    {
        for (int i=0; i<1001; i++)
        {
            so[i] = s[i];
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