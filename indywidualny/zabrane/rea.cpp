// Jakub Daszkiewicz
// zadanie Reakcje chemiczne

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct reaction
{
    vector<int> s, p;
    int i;
} emp;

int main()
{
    int n, k, r;
    scanf("%d %d %d", &n, &k, &r);
    bool c[n], ci[n];
    fill(c, c + n, false);
    int t, u;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &t);
        c[t] = true;
    }
    copy(c, c + n, ci);
    reaction tr;
    queue<reaction> q;
    for (int i = 0; i < r; i++)
    {
        tr = emp;
        scanf("%d", &t);
        for (int i = 0; i < t; i++)
        {
            scanf("%d", &u);
            tr.s.push_back(u);
        }
        scanf("%d", &t);
        for (int i = 0; i < t; i++)
        {
            scanf("%d", &u);
            tr.p.push_back(u);
        }
        tr.i = i;
        q.push(tr);
    }
    u = q.back().i;
    bool cf = true;
    while (!q.empty())
    {
        start:
        tr = q.front();
        q.pop();
        if (tr.i == u && !cf) break;
        cf = false;
        for (int i : tr.s)
        {
            if (!c[i])
            {
                q.push(tr);
                goto start;
            }
        }
        for (int i : tr.p)
        {
            c[i] = true;
        }
        u = q.front().i;
        cf = true;
    }
    t = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] && !ci[i]) t++;
    }
    printf("%d", t);
    return 0;
}