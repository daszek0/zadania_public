#include <iostream>
#include <stdio.h>
// #include <vector>

using namespace std;

int main()
{
    int w, n;
    scanf("%d", &w);
    scanf("%d", &n);
    int m[n];
    bool b[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &m[i]);
        b[i] = false;
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

    int r = 0;
    //vector <bool> k;

    for (int i=n-1; i>=0; i--)
    {
        if (b[i] == false)
        {
            for (int j=n-1; j>=0; j--)
            {
                if (i != j && b[j] == false && m[j]+m[i] <= w)
                {
                    b[j] = true;
                    b[i] = true;
                    r++;
                    break;
                }
                else if (j == 0)
                {
                    b[i] = true;
                    r++;
                }
            }
        }
    }

    printf("%d", r);

    return 0;
}
