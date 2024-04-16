// Jakub Daszkiewicz
// zadanie Przedziały

// test 1: 5 5 6 1 4 10 10 6 9 8 10 => 1 4 5 10

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool comp1(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first > p2.first) return false;
    return true;
}

bool comp2(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second > p2.second) return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> p;
    pair<int, int> t;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &t.first, &t.second);
        p.push_back(t);
    }
    sort(p.begin(), p.end(), comp2);
    sort(p.begin(), p.end(), comp1);
    for (int i=1; i<p.size(); i++)
    {
        if (p[i].first <= p[i-1].second)
        {
            p[i-1].second = p[i].second;
            p.erase(p.begin()+i);
            i--;
        }
    }
    for (int i=0; i<p.size(); i++)
    {
        printf("%d %d\n", p[i].first, p[i].second);
    }
    return 0;
}