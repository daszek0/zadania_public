// Jakub Daszkiewicz
// zadanie Bramki

#include <cstdio>
#include <vector>

using namespace std;

vector<int> g[10000], r[10000];
bool v[10000];
int s[10000];
bool d[10000];
// 0 -> s == -1
// 1/2 -> s == 0
// 1 -> s == 1
// ? -> d == false

int signum(int n)
{
    if (n < 0) return -1;
    else if (n > 0) return 1;
    return 0;
}

void dfs(int n)
{
    v[n] = true;
    for (int i : g[n])
    {
        if (!v[i])
        {
            int si = 0;
            int cb = 0;
            for (int j : r[i])
            {
                si += s[j];
                cb += d[j];
            }
            if (cb == r[i].size())
            {
                d[i] = true;
                s[i] = signum(si);
                dfs(i);
            }
        }
    }
}

int main()
{
    int n, k, x;
    scanf("%d", &n);
    s[0] = -1;
    d[0] = true;
    s[1] = 1;
    d[1] = true;
    for (int i = 2; i < n; i++)
    {
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &x);
            g[x].push_back(i);
            r[i].push_back(x);
        }
    }
    dfs(0);
    dfs(1);
    for (int i = 0; i < n; i++)
    {
        if (!d[i]) printf("?\n");
        else if (s[i] == -1) printf("0\n");
        else if (s[i] == 0) printf("1/2\n");
        else printf("1\n");
    }
    return 0;
}