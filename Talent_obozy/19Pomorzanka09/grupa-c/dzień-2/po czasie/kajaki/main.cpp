#include <bits/stdc++.h>

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

    // sortowanie
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
    // koniec sortowania

    /*for (int i=0; i<n; i++) // sprawdzenie sortowania
    {
        cout<<m[i]<<endl;
    }*/

    int k[n*2][2]; // kajaki
    for (int i=0; i<n*2;i++)
    {
        k[i][0] = -1;
        k[i][1] = -1;
    }

    int maximal[3];
    for (int i=n-1; i>=0; i--)
    {
        if (b[i] == false)
        {
            maximal[0] = m[i];
            maximal[1] = i;
            maximal[2] = -1;
            for (int j=n-1; j>=0; j--)
            {
                if (i != j)
                    {
                        if (m[i] + m[j] > maximal[0] && /*b[i] == false &&*/ b[j] == false && m[i] + m[j] <= w)
                        {
                            if (maximal[2] > -1)
                            {
                                // b[maximal[1]] = false;
                                b[maximal[2]] = false;
                            }
                            maximal[0] = m[i] + m[j];
                            // maximal[1] = i;
                            maximal[2] = j;
                            // b[i] = true;
                            b[j] = true;
                        }
                    }
            }
            /*if (b[i] == false)
            {*/
                int j = 0;
                while(k[j][0] != -1)
                {
                    j++;
                }
                k[j][0] = m[maximal[1]];
                if (maximal[2] == -1)
                    k[j][1] = -1;
                else
                    k[j][1] = m[maximal[2]];
                b[i] = true;
            // }
        }
    }
    int r = 0;
    for (int i=0; i<n*2; i++)
    {
        if (k[i][0] != -1)
            r++;
        else break;
    }

    printf("%d", r);

    return 0;
}
