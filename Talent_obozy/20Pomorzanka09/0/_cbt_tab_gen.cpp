// Jakub Daszkiewicz
// zadanie cock and ball torture tab generator

#include <stdio.h>

using namespace std;

typedef long long ll;

const ll m = 1000213769;

void cbt()
{
    ll xd = 7;
    for (ll i=2; i<1000000001; i++)
    {
        xd = (xd * xd + 1) % m;
        if (i % 1000000 == 0) printf(", %lld", xd);
    }
}

int main()
{
    cbt();
    
    return 0;
}