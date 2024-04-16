// Jakub Daszkiewicz
// zadanie Przedziały

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

inline void readUI(unsigned *i)
{
    register unsigned r=0;
    register char c=getchar_unlocked();
    while(c < '0' || c > '9')
    {
        c=getchar_unlocked();
    }
    while(c >= '0' && c <= '9')
    {
        r=(r<<3)+(r<<1)+c-'0';
        c=getchar_unlocked();
    }
    *i=r;
}

int main()
{
    unsigned n;
    readUI(&n);
    vector<pair<unsigned, unsigned>> p;
    pair<unsigned, unsigned> t;
    for (int i=0; i<n; i++)
    {
        readUI(&t.first);
        readUI(&t.second);
        p.emplace_back(t);
    }
    sort(p.begin(), p.end());
    for (int i=1; i<p.size(); i++)
    {
        if (p[i].first <= p[i-1].second)
        {
            p[i-1].second = max(p[i-1].second, p[i].second);
            p.erase(p.begin()+i);
            i--;
        }
    }
    for (int i=0; i<p.size(); i++)
    {
        printf("%u %u\n", p[i].first, p[i].second);
    }
    return 0;
}