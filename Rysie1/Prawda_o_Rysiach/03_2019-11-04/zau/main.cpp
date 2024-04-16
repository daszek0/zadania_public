#include <bits/stdc++.h>

using namespace std;

void skracansko_ulomkow(int &a, int &b)
{
    int gcd = __gcd(a, b);
    a /= gcd;
    b /= gcd;
}

int main()
{
    float W;
    scanf("%f", &W);
    int licznik = W*1000;
    int mianownik = 1000;
    skracansko_ulomkow(licznik, mianownik);
    printf("%d/%d", licznik, mianownik);
    return 0;
}
