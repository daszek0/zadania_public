// Jakub Daszkiewicz
// zadanie Symulator

#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int v[100000];

int check(int idx)
{
    if (idx == v[idx]) return 0;
    swap(v[idx], v[v[idx]]);
    return check(v[idx]) + 1;
}

int main()
{
    scanf("%d", &n);
    long long r = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
        v[i]--;
    }
    for (int i=0; i<n; i++)
    {
        r += check(i);
    }
    printf("%lld", r);
    return 0;
}