// Jakub Daszkiewicz
// zadanie Izolator

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    long long A = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        A += a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n >> 1; i++)
    {
        A += a[n - i - 1] - a[i];
    }
    printf("%lld", A);
    return 0;
}