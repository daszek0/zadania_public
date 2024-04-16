// Jakub Daszkiewicz
// zadanie Beczka

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    double s, h, v;
    int n;
    scanf("%lf %lf %lf", &s, &h, &v);
    double a = v;
    scanf("%d", &n);
    double l, d;
    for (int i=0; i<n; i++)
    {
        scanf("%lf %lf", &l, &d);
        a += l * l * l * min((double)1, d);
    }
    a /= s;
    printf("%.4lf\n", min(h, a));
    return 0;
}