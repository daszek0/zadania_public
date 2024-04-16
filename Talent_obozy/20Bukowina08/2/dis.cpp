// Jakub Daszkiewicz
// zadanie Domy i studnie

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m, s, t;
    scanf("%d %d", &n, &m);
    vector <pair <int, int>> p;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &s);
        for (int j=0; j<s; j++)
        {
            scanf("%d", &t);
            p.push_back(make_pair(i, t - 1));
        }
    }
    vector <int> c[p.size()];
    for (int i=0; i<p.size(); i++)
    {
        for (int j=i-1; j>=0; j--)
        {
            if (p[j].second >= p[i].second) c[i].push_back(j);
        }
        for (int j=i+1; j<p.size(); j++)
        {
            if (p[j].second <= p[i].second) c[i].push_back(j);
        }
    }
    priority_queue <pair <int, vector<pair<int, int>>::iterator>> q;
    for (int i=0; i<p.size(); i++)
    {
        if (c[i].size() != 0)
            q.push(make_pair(c[i].size(), p.begin()+i));
    }
    while (!q.empty())
    {
        while (*q.top().second == make_pair(-1, -1)) q.pop();
        *q.top().second = make_pair(-1, -1);
        for (int i=0; i<c[q.top().second - p.begin()].size(); i++) if (c[q.top().second - p.begin()][i] == q.top().second - p.begin()) c[q.top().second - p.begin()].erase(c[q.top().second - p.begin()].begin() + i);
        q.pop();
    }
    int r = 0;
    for (int i=0; i<p.size(); i++)
    {
        if (p[i] != make_pair(-1, -1)) r++;
    }
    printf("%d", r);
    return 0;
}