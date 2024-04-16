// Jakub Daszkiewicz
// zadanie Podział zamku

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> g[n];
    int t0, t1;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &t0, &t1);
        t0--;
        t1--;
        g[t0].push_back(t1);
        g[t1].push_back(t0);
    }
    queue<int> q;
    bool iq[n];
    fill(iq, iq + n, false);
    bool v[n];
    fill(v, v + n, 0);
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == 1)
        {
            q.push(i);
            iq[i] = true;
        }
    }
    int nc[n];
    fill(nc, nc + n, 0);
    do
    {
        v[q.front()] = true;
        for (int i : g[q.front()])
        {
            if (!v[i])
            {
                if (!iq[i])
                {
                    iq[i] = true;
                    q.push(i);
                }
                nc[i] += nc[q.front()] + 1;
            }
        }
        q.pop();
    } while (q.size() > 2);
    printf("%d", nc[q.back()] - nc[q.front()]);
    return 0;
}