#include <stdio.h>

using namespace std;

int n, k, s, a=0, r=0;

int main()
{
    scanf("%d %d %d", &n, &k, &s);
    int m[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &m[i]);
    }
    
	int minimal, taken;
    for (int i=0; i<n; i++)
    {
        minimal = m[i];
        for (int j=i+1; j<n; j++)
        {
            if (m[j]<minimal)
            {
                taken = minimal;
                minimal = m[j];
                m[j] = taken;
            }
        }
        m[i] = minimal;
    }

    for (int i=n-1; i>=0; i--)
    {
        if(r+m[i]<=s && a+1<=k)
        {
            r+=m[i];
            a++;
        }
    }

    printf("%d", r);
	
    return 0;
}
