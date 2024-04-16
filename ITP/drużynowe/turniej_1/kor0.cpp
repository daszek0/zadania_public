// Wild Algorithm Rangers
// zadanie Karol i korek

#include <stdio.h>
#include <vector>

using namespace std;

vector <int> graph[200000];
bool visited[200000];
long long nerves[200000];
int visited_counter[200000];
int crossings;
int days;
int result[200000];
// pair <int, int> trips[200000];

bool done;

void dfs(int from, int to)
{
    visited[from] = 1;
    visited_counter[from]++;
    if (from == to)
    {
        done = 1;
        return;
    }
    for (int i=0; i<graph[from].size(); i++)
    {
        if (!visited[graph[from][i]]) dfs(graph[from][i], to);
        if (done) return;
    }
    visited_counter[from]--;
}

int main()
{
    scanf("%d %d", &crossings, &days);
    int t, u, v;
    for (int i=0; i<crossings; i++)
    {
        scanf("%lld", &nerves[i]);
    }
    for (int i=0; i<crossings-1; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    for (int i=0; i<days; i++)
    {
        scanf("%d", &t);
        for (int j=0; j<t; j++)
        {
            scanf("%d %d", &u, &v);
            dfs(u-1, v-1);
            done = 0;
            fill(visited, visited+200000, 0);
        }
        for (int j=0; j<200000; j++)
        {
            if (visited_counter[j] == t)
            {
                result[i] += nerves[j];
            }
        }
        fill(visited_counter, visited_counter+200000, 0);
    }
    for (int i=0; i<days; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}