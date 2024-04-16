// Jakub Daszkiewicz
// bignumy

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct bignum
{
    bool m;
    vector <char> d;
    void read()
    {
        m = false;
        d.clear();
        char c = getchar_unlocked();
        while (c < '0' || c > '9') c = getchar_unlocked();
        if (c == '-')
        {
            m = true;
            c = getchar_unlocked();
        }
        while (c >= '0' && c <= '9')
        {
            d.push_back(c - '0');
            c = getchar_unlocked();
        }
        reverse(d.begin(), d.end());
    }
    void write()
    {
        if (m) putchar_unlocked('-');
        for (int i=d.size()-1; i>=0; i--)
        {
            putchar_unlocked(d[i] + '0');
        }
    }
    bool operator<(const bignum n)
    {
        if (m == n.m)
        {
            if (d.size() == n.d.size())
            {

            }
            else return (d.size() < n.d.size()) ^ m;
        }
        else return m;
    }
    bignum operator+(bignum n)
    {
        bignum ret = *this;
        if (ret.m == true && n.m == false)
        {
            ret.m = false;
            return n - ret;
        }
        if (ret.m == false && n.m == true)
        {
            n.m = false;
            return ret - n;
        }
        if (ret.d.size() < n.d.size()) swap(ret.d, n.d);
        for (unsigned i = 0; i < n.d.size(); i++)
        {
            ret.d[i] += n.d[i];
        }
        for (unsigned i=1; i<ret.d.size(); i++)
        {
            if (ret.d[i - 1] >= 10)
            {
                ret.d[i] += ret.d[i - 1] / 10;
                ret.d[i - 1] %= 10;
            }
        }
        char t;
        while (ret.d.back() >= 10)
        {
            t = ret.d.back();
            ret.d.back() = t % 10;
            ret.d.push_back(t / 10);
        }
        return ret;
    }
    void operator+=(const bignum n)
    {
        *this = *this + n;
    }
    bignum operator++()
    {
        *this += {false, {1}};
        return *this;
    }
    bignum operator++(int)
    {
        bignum ret = *this;
        ++*this;
        return ret;
    }
    bignum operator-(bignum n)
    {
        bignum ret = *this;
        if (ret.m == true && n.m == true)
        {
            ret.m = false;
            n.m = false;
            return {true, (ret + n).d};
        }

    }
    void operator-=(const bignum n)
    {
        *this = *this - n;
    }
    bignum operator--()
    {
        *this -= {false, {1}};
        return *this;
    }
    bignum operator--(int)
    {
        bignum ret = *this;
        --*this;
        return ret;
    }
};

int main()
{
    bignum a, b;
    a.read();
    b.read();
    (a + b).write();
    return 0;
}