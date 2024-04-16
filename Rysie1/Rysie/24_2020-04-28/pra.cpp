// Jakub Daszkiewicz
// zadanie Pranie

#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int friends, colors, r = 0;
    scanf("%d %d", &friends, &colors);
    priority_queue <pair <int, int>> clothes;
    vector <int> color;
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
        color.push_back(t);
    }
    sort(color.begin(), color.end());
    bool assigned = false;
    while (!clothes.empty())
    {
        if (color.empty() || clothes.top().first > color[color.size()-1])
        {
            r = -1;
            break;
        }
        assigned = false;
        for (int i=0; i<color.size(); i++)
        {
            if (clothes.top().first + clothes.top().second <= color[i])
            {
                clothes.pop();
                color.erase(color.begin() + i);
                r++;
                assigned = true;
                break;
            }
        }
        if (!assigned)
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