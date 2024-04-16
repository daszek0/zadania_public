// Jakub Daszkiewicz
// zadanie Podpisy

// test 1: 9 0 1 1 1 2 2 2 3 2 1 7 1 5 0 2 7 9 2 7 8 => 2 3 4 8 9

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> d;
vector<int> w[500];
int wt[500];
bool v[500];

void dfs(int p)
{
    v[p] = 1;
    wt[p]++;
    for (int i=0; i<w[p].size(); i++)
    {
        if (!v[w[p][i]])
        {
            dfs(w[p][i]);
        }
    }
}

int main()
{
    int n, m, t;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &m);
        if (m == 0)
        {
            d.push_back(i);
            wt[i] = 2137;
        }
        for (int j=0; j<m; j++)
        {
            scanf("%d", &t);
            w[t-1].push_back(i);
        }
    }
    for (int i=0; i<d.size(); i++)
    {
        dfs(d[i]);
        for (int j=0; j<500; j++) v[j] = 0;
    }
    bool r = false;
    for (int i=0; i<500; i++)
    {
        if (wt[i] == 1)
        {
            printf("%d\n", i+1);
            r = true;
        }
    }
    if (!r) printf("BRAK\n");
    return 0;
}