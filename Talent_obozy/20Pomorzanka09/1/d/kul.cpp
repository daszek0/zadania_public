// Jakub Daszkiewicz
// zadanie Kulki

#include <stdio.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;
ll pt[2001][2001]; // prójkąt tascala

void fpt()
{
    pt[0][0] = 1;
    for (int i=1; i<2001; i++)
    {
        pt[i][0] = 1;
        pt[i][i] = 1;
        for (int j=0; j<i-1; j++)
        {
            pt[i][j+1] = (pt[i-1][j] + pt[i-1][j+1]) % mod;
        }
    }
}

ll f(ll x, ll y)
{
    return pt[x + y - 1][y - 1];
}

int main()
{
    fpt();
    int n, b;
    scanf("%d %d", &n, &b);
    for (int i=1; i<=b; i++)
    {
        // if (b > i && n - b > i - 1) printf("0\n");
        /* else  */printf("%lld\n", (f(b - i, i) * f(n - b - i + 1, i + 1)) % mod);
    }
    return 0;
}