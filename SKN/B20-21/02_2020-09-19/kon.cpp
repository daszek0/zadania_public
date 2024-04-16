// Jakub Daszkiewicz
// zadanie Konduktorzy

#include <stdio.h>
#include <queue>

typedef long long ll;

using namespace std;

int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll t[k], p = 1, lp[k];
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;
    for (ll i=0; i<k; i++)
    {
        scanf("%lld", &t[i]);
        lp[i] = p;
        q.push(make_pair(t[i], i));
        p++;
    }
    while (p <= n)
    {
        lp[q.top().second] = p;
        q.push(make_pair(q.top().first + t[q.top().second], q.top().second));
        p++;
        q.pop();
    }
    for (ll i=0; i<k; i++)
    {
        printf("%lld ", lp[i]);
    }
    return 0;
}