// Jakub Daszkiewicz
// zadanie Podobne sieci

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int q, n, t0, t1, id = -1;
vector <int> g0[20001];
vector <int> g1[20001];
vector <int> n0;
// vector <int> n1[20001];
vector <int> c0;
vector <int> c1;
map <vector <int>, int> m;
bool r;

int main()
{
    scanf("%d", &q);
    for (int p=0; p<q; p++)
    {
        r = true;
        scanf("%d", &n);
        for (int i=0; i<(2*n-3); i++)
        {
            scanf("%d %d", &t0, &t1);
            g0[t0].push_back(t1);
            g0[t1].push_back(t0);
        }
        scanf("%d", &t0);
        if (t0 != n)
        {
            for (int i=0; i<(2*t0-3); i++) scanf("%d %d");
            printf("NIE\n");
            continue;
        }
        for (int i=0; i<(2*n-3); i++)
        {
            scanf("%d %d", &t0, &t1);
            g1[t0].push_back(t1);
            g1[t1].push_back(t0);
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=0; j<g0[i].size(); j++)
            {
                n0.push_back(g0[g0[i][j]].size());
            }
            sort(n0.begin(), n0.end());
            m[n0]++;
            n0.clear();
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=0; j<g1[i].size(); j++)
            {
                n0.push_back(g1[g1[i][j]].size());
            }
            sort(n0.begin(), n0.end());
            m[n0]--;
            if (m[n0] < 0)
            {
                r = false;
            }
            n0.clear();
        }
        // for (int i=0; i<n; i++)
        // {
        //     sort(n1[i].begin(), n1[i].end());
        //     if (m.count(n0[i]) == 0)
        //     {
        //         id++;
        //         m[n0[i]] = id;
        //     }
        //     if (m.count(n1[i]) == 0)
        //     {
        //         id++;
        //         m[n1[i]] = id;
        //     }
        // }
        // for (int i=0; i<n; i++)
        // {
        //     c0.push_back(m[n0[i]]);
        //     c1.push_back(m[n1[i]]);
        // }
        // sort(c0.begin(), c0.end());
        // sort(c1.begin(), c1.end());
        if (r) printf("TAK\n");
        else printf("NIE\n");
        for (int i=0; i<20001; i++)
        {
            g0[i].clear();
            g1[i].clear();
            // n1[i].clear();
        }
        n0.clear();
        c0.clear();
        c1.clear();
        m.clear();
    }
    return 0;
}