// Jakub Daszkiewicz
// zadanie Kłopotliwy spadek

#include <cstdio>

using namespace std;

int main()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%.2lf", double(n * n) / (double)18 + double(n * m) / (double)9 + double(m * m) / (double)18 - double(n * m) / (double)12 - double(m * m) / (double)12);
    return 0;
}