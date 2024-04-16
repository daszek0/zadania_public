// Jakub Daszkiewicz
// zadanie Beczka

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    double s, h, v; // pole podstawy beczki, wysokość beczki, objętość kompotu wiśniowego
    int n; // liczba sześcianów
    scanf("%lf %lf %lf", &s, &h, &v);
    double a = 0; // objętość po zanurzeniu [j³]
    scanf("%d", &n);
    double l[n], d[n]; // krawędź, gęstość
    double p;
    for (int i=0; i<n; i++)
    {
        scanf("%lf %lf", &l[i], &d[i]);
    }
    for (int i=0; i<n; i++)
    {
        for (int i=0; i<100; i++)
        {
            
        }
        a += l[i] * l[i] * min(l[i] * min((double)1, d[i]), p) + max(0, p + l[i] - (l[i] * d[i] + h));
    }
    a += v;
    a /= s;
    printf("%.4lf\n", min(h, a));
    return 0;
}