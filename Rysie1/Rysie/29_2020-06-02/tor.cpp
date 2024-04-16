// Jakub Daszkiewicz
// zadanie Tort imieninowy

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d/%d", m/__gcd(m, n), n/__gcd(m, n));
    return 0;
}