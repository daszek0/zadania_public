// Jakub Daszkiewicz
// zadanie Gra platformowa

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

vector<pair<int, bool>> g[6100002]; // graf
int d[6100002]; // odległości

void qinp(int *n)
{
    int i = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
        c = getchar_unlocked();
    while (c >= '0' && c <= '9')
    {
        i = (i << 3) + (i << 1) + c - '0';
        c = getchar_unlocked();
    }
    *n = i;
}

void dijkstra()
{
    deque<int> q;
    fill(d, d + 6100002, __INT32_MAX__);
    q.push_back(0);
    d[0] = 0;
    int c;
    while (!q.empty())
    {
        c = q.front();
        q.pop_front();
        for (pair<int, bool> i: g[c])
        {
            if (d[c] + i.second < d[i.first])
            {
                d[i.first] = d[c] + i.second;
                if (i.second)
                    q.push_back(i.first);
                else
                    q.push_front(i.first);
            }
        }
    }
}

int main()
{
    int n, X, z;
    qinp(&n);
    qinp(&X);
    qinp(&z);
    int unn = n + 1; // ostatni numer wierzchołka
    vector<pair<int, int>> cr; // bieżący wiersz
    vector<pair<int, int>> pr; // poprzedni wiersz
    vector<pair<int, int>>::iterator cc; // bieżący z bieżącego wiersza
    vector<pair<int, int>>::iterator pc; // bieżący z poprzedniego wiersza
    int k, t;
    int nl, nr, nd;
    for (int i = 1; i <= n; i++)
    {
        qinp(&k);
        for (int i = 0; i < k; i++)
        {
            qinp(&t);
            cr.push_back(make_pair(t, -1));
        }
        t = i;
        cc = cr.begin();
        pc = pr.begin();
        while (cc != cr.end() || pc != pr.end())
        {
            if (cc == cr.end())
                k = 1;
            else if (pc == pr.end())
                k = 0;
            else if (pc->first <= cc->first)
                k = 1;
            else if (cc->first < pc->first)
                k = 0;
            if (k)
            {
                nl = pc->second;
                g[nl].push_back(make_pair(t, 0));
                t = nl;
                pc++;
            }
            else
            {
                cc->second = unn;
                nd = unn;
                unn++;
                if (pr.begin() != pr.end() &&pc != pr.end() && pc->first == cc->first + 1)
                {
                    nr = pc->second;
                }
                else
                {
                    nr = unn;
                    unn++;
                }
                nl = t;
                g[nr].push_back(make_pair(nd, 1));
                g[nd].push_back(make_pair(nl, 0));
                t = nr;
                cc++;
            }
        }
        g[0].push_back(make_pair(t, 0));
        pr = cr;
        cr.clear();
    }
    dijkstra();
    for (int i = 0; i < z; i++)
    {
        qinp(&t);
        printf("%d\n", d[t]);
    }
    return 0;
}