// Jakub Daszkiewicz
// zadanie Pole wielokąta

#include <stdio.h>
#include <algorithm>

using namespace std;

int min_a(bool fs, pair <int, int> p[], int l)
{
    int r;
    if (!fs) r = p[0].first;
    else r = p[0].second;
    for (int i=1; i<l; i++)
    {
        if (!fs) r = min(r, p[i].first);
        else r = min(r, p[i].second);
    }
    return r;
}

int max_a(bool fs, pair <int, int> p[], int l)
{
    int r;
    if (!fs) r = p[0].first;
    else r = p[0].second;
    for (int i=1; i<l; i++)
    {
        if (!fs) r = max(r, p[i].first);
        else r = max(r, p[i].second);
    }
    return r;
}

int main()
{
    int n;
    scanf("%d", &n);
    pair <int, int> w[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &w[i].first, &w[i].second);
    }
    int x_min = min_a(0, w, n);
    int x_max = max_a(0, w, n);
    int y_min = min_a(1, w, n);
    int y_max = max_a(1, w, n);
    long long dp = (x_max - x_min) * (y_max - y_min);

    return 0;
}