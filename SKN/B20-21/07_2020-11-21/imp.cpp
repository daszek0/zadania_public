// Jakub Daszkiewicz
// zadanie Impreza masowa

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int m[n], mm[2];
    long long st[n];
    scanf("%d", &m[0]);
    st[0] = m[0];
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &m[i]);
        st[i] = st[i - 1] + m[i];
    }
    mm[0] = m[1];
    mm[1] = m[0];
    if (mm[0] < mm[1])
        swap(mm[0], mm[1]);
    st[0] <<= 1;
    st[1] <<= 1;
    for (int i = 2; i < n; i++)
    {
        if (m[i] > mm[1])
        {
            if (m[i] > mm[0])
            {
                mm[1] = mm[0];
                mm[0] = m[i];
            }
            else
                mm[1] = m[i];
        }
        st[i] += mm[0] + mm[1];
    }
    pair<long long, int> s[q];
    int a[q];
    for (int i = 0; i < q; i++)
    {
        scanf("%lld", &s[i].first);
        s[i].second = i;
    }
    sort(s, s + q);
    int it = 0;
    for (int i = 0; i < n; i++)
    {
        while (st[i] > s[it].first)
        {
            a[s[it].second] = i;
            it++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}