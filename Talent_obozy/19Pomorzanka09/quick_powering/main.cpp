#include <iostream>

using namespace std;

long long qpow(long long a, long long n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return a;
    else if (n%2 == 0)
    {
        long long r = qpow(a, n/2);
        return r*r;
    }
    else
    {
        long long r = qpow(a, n-1);
        return a*r;
    }
}

int main()
{
    cout << qpow(2,13) << endl;
    return 0;
}
