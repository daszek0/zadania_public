// Wild Algorithm Rangers
// zadanie Spójne składowe

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct point
{
    int x;
    int y;
    int c;
};

point p[1000001];
int n, x, y, c, idx, mc;

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
        if (i == 0)
        {
            p[i].c = 1;
            mc = 1;
        }
        else
        {
            if (p[i-1].x == p[i].x && p[i-1].y == p[i].y - 1)
            {
                p[i].c = p[i-1].c;
            }
            else
            {
                mc++;
                p[i].c = mc;
            }
            x = p[i].x;
            y = p[i].y-1;
            idx = i;
            while (x >= p[i].x - 1 && y != p[i].y && idx > 0)
            {
                idx--;
                x = p[idx].x;
                y = p[idx].y;
                c = p[idx].c;
            }
            if (y == p[i].y)
            {
                for (int j=i-1; j>=0; j--)
                {
                    if (p[j].c == c)
                    {
                        p[j].c = p[i].c;
                    }
                }
            }
        }
    }
    int cs[mc+1];
    fill(cs, cs+mc+1, 0);
    for (int i=0; i<1000001; i++)
    {
        cs[p[i].c]++;
    }
    vector <int> r;
    for (int i=1; i<=mc; i++)
    {
        if (cs[i] != 0) r.push_back(cs[i]);
    }
    sort(r.begin(), r.end());
    printf("%d\n", r.size());
    for (int i=0; i<r.size(); i++)
    {
        printf("%d ", r[i]);
    }
    return 0;
}