// Jakub Daszkiewicz
// zadanie Drogi zmiennokierunkowe

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> go[500001];
vector<int> ge[500001];
bitset<500001> r[500001];
int v[500001];

void dfso(int n, int f)
{
    r[n][f] = true;
    v[n] = 1;
    for (int i : go[n])
    {
        if (!v[i])
        {
            dfso(i, f);
        }
    }
}

void dfse(int n, int f)
{
    r[n][f] = 1;
    v[n] = 1;
    for (int i : ge[n])
    {
        if (!v[i])
        {
            dfse(i, f);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        go[a].push_back(b);
        ge[b].push_back(a);
    }
    for (int i = 1; i < n + 1; i++)
    {
        fill(v, v + 500001, 0);
        dfso(i, i);
        fill(v, v + 500001, 0);
        dfse(i, i);
    }
    vector<int> ans;
    for (int i = 1; i < n + 1; i++)
    {
        if (r[i].count() == n)
        {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%lu", ans.size());
    for (int i : ans)
    {
        printf("%d", i);
    }
    return 0;
}