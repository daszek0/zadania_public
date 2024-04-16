// Jakub Daszkiewicz
// zadanie Mikołajkowe torebki

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, t, min_ = 2001, max_ = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        min_ = min(min_, t);
        max_ = max(max_, t);
    }
    printf("%d", max_ - min_);
    return 0;
}