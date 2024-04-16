// Jakub Daszkiewicz
// zadanie Pole
//
// test 1: 0 3 4 0 2 4 6 1 => 4

#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    pair<int,int> x1, x2, y1, y2;
    scanf("%d %d %d %d", &x1.first, &y1.second, &x1.second, &y1.first);
    scanf("%d %d %d %d", &x2.first, &y2.second, &x2.second, &y2.first);
    long long x = min(x1.second, x2.second) - max(x1.first, x2.first);
    long long y = min(y1.second, y2.second) - max(y1.first, y2.first);
    if (x < 0 || y < 0)
        printf("0");
    else
        printf("%lld", x*y);
    return 0;
}