// Jakub Daszkiewicz
// zadanie Rezerwacja sal wykładowych

// test 1: 12 1 2 3 5 0 4 6 8 7 13 4 6 9 10 9 12 11 14 15 19 14 16 18 20 => 16

#include <stdio.h>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second > p2.second) return false;
    else return true;
}

inline void readUI(unsigned int *i)
{
    register int r=0;
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
    unsigned int n;
    readUI(&n);
    // scanf("%d", &n);
    pair<unsigned int, unsigned int> t[n];
    unsigned int t1, t2;
    int h[30001];
    for (int i=0; i<30001; i++)
    {
        h[i] = 0;
    }
    for (int i=0; i<n; i++)
    {
        readUI(&t1);
        readUI(&t2);
        // scanf("%d %d", &t[i].first, &t[i].second);
        t[i].first = t1;
        t[i].second = t2;
    }
    sort(t, t+n, comp);
    int v, m;
    for (int i=0; i<n; i++)
    {
        m = 0;
        v = t[i].second - t[i].first;
        for (int j=i-1; j>=0; j--)
        {
            if (t[j].second <= t[i].first)
            {
                m = max(m, h[t[j].second]);
            }
        }
        h[t[i].second] = max(h[t[i].second], m + v);
    }
    int r = 0;
    for (int i=0; i<n; i++)
    {
        r = max(r, h[t[i].second]);
    }
    printf("%d", r);
    return 0;
}