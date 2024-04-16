#include <stdio.h>
using namespace std;
int main()
{
	long long n, m, r=0;
	scanf("%lli", &n);
	long long c[n];
	for(int i=0;i<n;i++)
        scanf("%lli", &c[i]);
    m = c[n-1];
    for(int i=n-1;i>=0;i--)
    {
        if(c[i]<m)
            m = c[i];
        r += m;
    }
    printf("%lli", r);
    return 0;
}
