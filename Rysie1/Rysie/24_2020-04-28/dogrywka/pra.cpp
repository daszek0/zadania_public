// Jakub Daszkiewicz
// zadanie Pranie

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int friends, colors, r = 0;
    scanf("%d %d", &friends, &colors);
    priority_queue <pair <int, int>> clothes;
    multiset <int> color;
    int t;
    pair <int, int> tp;
    for (int i=0; i<friends; i++)
    {
        scanf("%d", &t);
        clothes.push(make_pair(3*t, 2*t));
    }
    for (int i=0; i<colors; i++)
    {
        scanf("%d", &t);
        color.insert(t);
    }
    while (!clothes.empty())
    {
        if (color.empty() || color.lower_bound(clothes.top().first) == color.end())
        {
            r = -1;
            break;
        }
        auto p = color.lower_bound(clothes.top().first + clothes.top().second);
        if (p != color.end())
        {
            clothes.pop();
            color.erase(p);
            r++;
        }
        else
        {
            tp = clothes.top();
            clothes.pop();
            clothes.push(make_pair(tp.first, 0));
            clothes.push(make_pair(tp.second, 0));
        }
    }
    if (r == -1) printf("NIE");
    else printf("%d", r);
    return 0;
}