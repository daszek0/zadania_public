// Jakub Daszkiewicz
// zadanie Przejazd drezyną

// test 1: 9 9 1 2 3 4 5 6 7 8 9 5 7 2 8 2 6 9 1 7 3 1 8 6 2 4 7 => 100

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> connections[1001];
bool visited[1001];
int set[1001];

bool all_visited(int limit)
{
    for (int i=0; i<limit; i++)
    {
        if (visited[i] == 0) return false;
    }
    return true;
}

void dfs(int city, int c_set)
{
    visited[city] = 1;
    set[city] = c_set;
    for (int i=0; i<connections[city].size(); i++)
    {
        if (visited[connections[city][i]] == 0)
        {
            dfs(connections[city][i], c_set);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int t1, t2;
    for (int i=0; i<m; i++)
    {
        scanf("%d%d", &t1, &t2);
        connections[t1-1].push_back(t2-1);
        connections[t2-1].push_back(t1-1);
    }
    int c_set = 1;
    while (!all_visited(n))
    {
        for (int i=0; i<n; i++)
        {
            if (!visited[i])
            {
                dfs(i, c_set);
                break;
            }
        }
        c_set++;
    }
    int q;
    scanf("%d", &q);
    for (int i=0; i<q; i++)
    {
        scanf("%d%d", &t1, &t2);
        printf("%d", (int)(set[t1-1] == set[t2-1]));
    }
    return 0;
}