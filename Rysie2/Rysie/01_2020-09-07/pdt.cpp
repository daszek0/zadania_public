// Jakub Daszkiewicz
// zadanie Podatki

#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int t;
    priority_queue <int> q;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        q.push(t);
    }
    bool p = false;
    int a = 0;
    while (true)
    {
        if (p)
        {
            if (q.top() < 2) break;
            q.push(q.top() - 2);
            a += 2;
        }
        else
        {
            if (q.top() < 1) break;
            q.push(q.top() - 1);
            a++;
        }
        q.pop();
        p ^= 1;
    }
    printf("%d", a);
    return 0;
}