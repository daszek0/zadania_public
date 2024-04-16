#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    scanf("%d", &m);
    int n[m], r[m]/*, a[m][100000]*/;
    vector <int> a[m];
    for (int i=0; i<m; i++)
    {
        scanf("%d", &n[i]);
        for (int j=0; j<n[i]; j++)
        {
            int l;
            scanf("%d", &l);
            a[i].push_back(l);
        }
        r[i] = -1;
    }
    for (int i=0; i<m; i++)
    {
        int f = 1, b = 1;
        for (int j=0; j<n[i]-1; j++)
        {
            if (a[i][j] == a[i][j+1])
                f++;
            else break;
        }
        for (int j=n[i]-1; j>0; j--)
        {
            if (a[i][j] == a[i][j-1])
                b++;
            else break;
        }

        if (f == n[i])
            r[i] = 0;
        else if (a[i][0] == a[i][n[i]-1])
        {
            if (f == b)
            {
                r[i] = n[i]-f-1;
            }
            else if (f > b)
            {
                r[i] = n[i]-b-1;
            }
            else if (f < b)
            {
                r[i] = n[i]-f-1;
            }
        }
        else if (a[i][0] != a[i][n[i]-1])
        {
            if (f == b)
            {
                r[i] = n[i]-f;
            }
            else if (f > b)
            {
                r[i] = n[i]-b;
            }
            else if (f < b)
            {
                r[i] = n[i]-f;
            }
        }



        /*
        else if (f == b && a[i][0] == a[i][n[i]-1])
            r[i] = n[i]-f-1;
        else if (f == b && a[i][0] != a[i][n[i]-1])
            r[i] = n[i]-f;
        else if (f < b && a[i][0] == a[i][n[i]-1])
            r[i] = n[i]-b;
        else if (f > b && a[i][0] == a[i][n[i]-1])
            r[i] = n[i]-f;
        else if (f < b && a[i][0] != a[i][n[i]-1])
            r[i] = n[i]-f;
        else if (f > b && a[i][0] != a[i][n[i]-1])
            r[i] = n[i]-b;*/
        /*else
            r[i] = n[i]-f-b+1;*/
    }
    for (int i=0; i<m; i++)
    {
        if (r[i] == 0)
            printf("BRAK\n");
        else
            printf("%d\n", r[i]);
    }
    return 0;
}
