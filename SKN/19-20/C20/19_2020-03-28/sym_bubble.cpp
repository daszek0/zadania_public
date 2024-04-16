// Jakub Daszkiewicz
// zadanie Symulator

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int v[n];
    long long r = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    while (n > 1)
    {
        for (int i=0; i<n-1; i++)
        {
            if (v[i] > v[i+1])
            {
                swap(v[i], v[i+1]);
                r++;
            }
        }
        n--;
    }
    printf("%lld", r);
    return 0;
}