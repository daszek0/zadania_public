// Jakub Daszkiewicz
// zadanie Działka

#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar_unlocked();
    int h[n];
    fill(h, h+n, 0);
    int c;
    stack <pair <int, int>> s;
    int p, r = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &c);
            if (c == 1) h[j] = 0;
            else h[j]++;
        }
        p = 0;
        s.push(make_pair(0, 0));
        for (int j=0; j<n; j++)
        {
            p = j;
            while (!s.empty() && s.top().first > h[j])
            {
                r = max(r, s.top().first * (j - s.top().second));
                p = s.top().second;
                s.pop();
            }
            // while (s.top().first > h[j-1]) s.pop();
            if (h[j]) s.push(make_pair(h[j], p));
        }
        while (!s.empty())
        {
            r = max(r, s.top().first * (n - s.top().second));
            s.pop();
        }
    }
    printf("%d", r);
    return 0;
}