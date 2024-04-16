// #include <iostream>
#include <stdio.h>

using namespace std;

int n, m, r = 0;

int main()
{
    scanf("%d %d", &n, &m);
    int a[m][2];
    for(int i=0; i<m; i++)
        scanf("%d %d", &a[i][0], &a[i][1]);

    /*  // sortowanie tablicy
    int minimal[2], taken[2];
    for (int i=0; i<m; i++)
    {
        minimal[0] = a[i][0];
        minimal[1] = a[i][1];
        for (int j=i+1; j<m; j++)
        {
            if (a[j][0]<minimal[0])
            {
                taken[0] = minimal[0];
                taken[1] = minimal[1];
                minimal[0] = a[j][0];
                minimal[1] = a[j][1];
                a[j][0] = taken[0];
                a[j][1] = taken[1];
            }
        }
        a[i][0] = minimal[0];
        a[i][1] = minimal[1];
    }
    int minimal1, taken1, over = m;
    for(int h=1; h<=n; h++)
    {
        for (int i=0; i<m; i++)
        {
            for (int j=i; j<m; j++)
                if (a[j][0]>h)
                {
                    over = j;
                    break;
                }
            if(a[i][0] == h)
            {
                minimal1 = a[i][1];
                for (int j=i+1; j<over; j++)
                {
                    if (a[i][1]<minimal1)
                    {
                        taken1 = minimal1;
                        minimal1 = a[j][1];
                        a[j][1] = taken1;
                    }
                }
                a[i][1] = minimal1;
            }
        }
    }
    // koniec sortowania tablicy  */

    if(a[0][0] == a[1][0] && a[0][1] == a[1][1])
        r++;

    for (int i=1; i<m-1; i++)
    {
        if((a[i][0] == a[i-1][0] && a[i][1] == a[i-1][1]) || (a[i][0] == a[i+1][0] && a[i][1] == a[i+1][1]) || (a[i][0] == a[i+1][0] && a[i][1] == a[i-1][1]) || (a[i][0] == a[i-1][0] && a[i][1] == a[i+1][1]))
            r++;
    }

    if(a[m-1][0] == a[m-2][0] && a[m-1][1] == a[m-2][1])
        r++;

    printf("%d", r);

    /*for (int i=0; i<m; i++)
        cout<<a[i][0]<<" "<<a[i][1]<<endl;*/

    return 0;
}
