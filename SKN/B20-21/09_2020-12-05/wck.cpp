// Jakub Daszkiewicz
// zadanie Jesienna Wycieczka

#include <stdio.h>
#include <vector>

using namespace std;

bool a;
vector<int> g[100000];
bool v[100000];
vector<int> p;
int ip[100000];

void dfs(int n, int f)
{
    v[n] = true;
    p.push_back(n);
    ip[n]++;
    for (int i : g[n])
    {
        if (i == f)
            continue;
        if (!v[i])
            dfs(i, n);
        else if (ip[i])
        {
            int j = 1;
            while (p[p.size() - 1 - j] != i)
                j++;
            if (j & 1)
            {
                a = true;
                return;
            }
        }
    }
    p.pop_back();
    ip[n]--;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int t0, t1;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &t0, &t1);
        g[t0].push_back(t1);
        g[t1].push_back(t0);
    }
    for (int i = 0; i < n; i++)
    {
        if (!v[i] && !a)
            dfs(i, -1);
    }
    if (a)
        printf("JEST");
    else
        printf("BRAK");
    return 0;
}