// Jakub Daszkiewicz
// zadanie Trójkąty
//
// test 1: 8 13/10 1/2 6/5 11/6 9/7 13/10 9/5 8/5 => NIE
// test 2: 5 1/2 3/5 4/7 1/1 4/6 => TAK

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, temp;
    scanf("%d", &n);
    long double a[n];
    for (int i=0; i<n; ++i)
    {
        scanf("%llf/%d", &a[i], &temp);
        a[i] /= temp;
    }
    sort(a, a+n);
    if (a[0]+a[1] > a[n-1]) printf("TAK");
    else printf("NIE");
    return 0;
}