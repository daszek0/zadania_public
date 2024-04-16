#include <stdio.h>
#include <iostream>

using namespace std;

int n, k, s, a=0, r=0;
// x[i] = minimal;
/*int sortArray(int a[], int l)
{
    int minimal = a[0], taken;
    for (int i=0; i<l; i++)
    {
        for (int j=i; j<l; j++)
        {
            if (a[j]<minimal)
            {
                taken = minimal;
                minimal = a[j];
                a[j] = taken;
            }
        }
    }
    return a[l];
}*/

int main()
{
    scanf("%d %d %d", &n, &k, &s);
    int m[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &m[i]);
    }
    // cout<<n<<k<<s;

    /*int y = 5; // gówno jebane
    int x[y];
    for (int i=0; i<y; i++)
        cin>>x[i];*/

    // sortowanie tablicy
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
    // koniec sortowania tablicy

    for (int i=n-1; i>=0; i--)
    {
        if(r+m[i]<=s && a+1<=k)
        {
            r+=m[i];
            a++;
        }
    }

    printf("%d", r);

    /*for (int i=0; i<n; i++)  // wypisanie tablicy
        cout<<m[i];*/
    return 0;
}
