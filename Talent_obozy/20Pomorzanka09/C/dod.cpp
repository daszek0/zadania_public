// Jakub Daszkiewicz
// zadanie Dodawanie

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <char> bignum;

bignum bignum_read()
{
    bignum ret;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();
    while (c >= '0' && c <= '9')
    {
        ret.push_back(c - '0');
        c = getchar_unlocked();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void bignum_write(bignum n)
{
    for (int i=n.size()-1; i>=0; i--)
    {
        putchar_unlocked(n[i] + '0');
    }
}

bignum operator+(bignum n0, bignum n1)
{
    if (n0.size() < n1.size()) swap(n0, n1);
    for (unsigned i = 0; i < n1.size(); i++)
    {
        n0[i] += n1[i];
    }
    for (unsigned i=1; i<n0.size(); i++)
    {
        if (n0[i - 1] >= 10)
        {
            n0[i] += n0[i - 1] / 10;
            n0[i - 1] %= 10;
        }
    }
    char t;
    while (n0.back() >= 10)
    {
        t = n0.back();
        n0.back() = t % 10;
        n0.push_back(t / 10);
    }
    return n0;
}

int main()
{
    bignum a, b;
    a = bignum_read();
    b = bignum_read();
    bignum_write(a + b);
    return 0;
}