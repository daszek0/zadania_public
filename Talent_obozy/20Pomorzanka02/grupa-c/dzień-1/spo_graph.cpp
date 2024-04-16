// Jakub Daszkiewicz
// zadanie Sponsor

// test: 23.600 23.400 22.610 24.420 22.400 22.220 21.800 22.800 20.800 0 => 700

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[10001];
int rt = 0, r = 0;

void dfs(int x)
{
    rt++;
    if (graph[x].empty())
    {
        r = max(r, rt);
    }
    else
    {
        for (int i=0; i<graph[x].size(); i++)
        {
            dfs(graph[x][i]);
        }
    }
    rt--;
}

int main()
{
    vector<double> t;
    double temp;
    while (true)
    {
        scanf("%lf", &temp);
        if (temp == 0) break;
        t.push_back(temp);
    }
    bool start[t.size()];
    for (int i=0; i<t.size(); i++)
    {
        start[i] = true;
    }
    for (int i=0; i<t.size(); i++)
    {
        for (int ii=i+1; ii<t.size(); ii++)
        {
            if (t[i] > t[ii])
            {
                graph[i].push_back(ii);
                start[ii] = false;
            }
        }
    }
    for (int i=0; i<t.size(); i++)
    {
        if (start[i]) dfs(i);
    }
    printf("%d", r*100);
    return 0;
}