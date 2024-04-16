// Jakub Daszkiewicz
// zadanie Pole wielokąta

#include <stdio.h>
#include <algorithm>
#include <math.h>

#define x first
#define y second

using namespace std;

typedef pair <int, int> point;

double odl(point p1, point p2)
{
    return sqrt(abs(p1.x - p2.x)*abs(p1.x - p2.x) + abs(p1.y - p2.y)*abs(p1.y - p2.y));
}

double p(point A, point B, point C)
{
    double a = odl(A, B);
    double b = odl(B, C);
    double c = odl(C, A);
    double o = (a+b+c)/2;
    return sqrt(o*(o-a)*(o-b)*(o-c));
}

int main()
{
    int n;
    scanf("%d", &n);
    point w[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &w[i].x, &w[i].y);
    }
    double r = 0;
    for (int i=1; i<n-1; i++)
    {
        r += p(w[0], w[i], w[i+1]);
    }
    printf("%.2lf", r);
    return 0;
}