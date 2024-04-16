// Jakub Daszkiewicz
// zadanie Liczbowy proces

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct quest
{
    unsigned long long v;
    int n;
    bool a;
};

unsigned long long g[2962717];

bool quest_value(quest q0, quest q1)
{
    return (q0.v < q1.v);
}

bool quest_number(quest q0, quest q1)
{
    return (q0.n < q1.n);
}

unsigned long long ds(unsigned long long n)
{
    unsigned long long r = 0;
    while (n > 0)
    {
        r += n % 10;
        n /= 10;
    }
    return r;
}

void fill_g()
{
    g[0] = 1;
    unsigned long long s;
    for (int i=1; i<2962717; i++)
    {
        s = ds(g[i - 1]);
        g[i] = g[i - 1] + s * s;
    }
}

int main()
{
    fill_g();
    int n;
    scanf("%d", &n);
    quest m[n];
    for (int i=0; i<n; i++)
    {
        scanf("%llu", &m[i].v);
        m[i].n = i;
    }
    sort(m, m+n, quest_value);
    int i = 0, j = 0;
    while (i < n)
    {
        if (m[i].v == g[j])
        {
            m[i].a = true;
            i++;
        }
        else if (m[i].v > g[j])
        {
            j++;
        }
        else
        {
            m[i].a = false;
            i++;
        }
    }
    sort(m, m+n, quest_number);
    for (int i=0; i<n; i++)
    {
        if (m[i].a) printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}