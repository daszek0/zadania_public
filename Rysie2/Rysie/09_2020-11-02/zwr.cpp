// Jakub Daszkiewicz
// zadanie Zwrotnice

#include <stdio.h>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

vector<pair<int, int>> g[100000]; // wartość krawędzi, cel

int dijkstra(int from, int to)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    bitset<100000> v;
    v.reset();
    q.push(make_pair(0, from));
    pair <int, int> curr;
    while (!q.empty())
    {
        curr = q.top();
        v[curr.second] = true;
        q.pop();
        if (curr.second == to) return curr.first;
        for (auto d: g[curr.second])
        {
            if (!v[d.second]) q.push(make_pair(curr.first + d.first, d.second));
        }
    }
    return -1;
}

int main()
{
    int n, f, t;
    scanf("%d %d %d", &n, &f, &t);
    f--;
    t--;
    int b, c;
    for (int a = 0; a < n; a++)
    {
        scanf("%d %d", &b, &c);
        b--;
        c--;
        g[a].push_back(make_pair(0, b));
        g[a].push_back(make_pair(1, c));
    }
    int a = dijkstra(f, t);
    if (a == -1) printf("BRAK");
    else printf("%d", a);
    return 0;
}