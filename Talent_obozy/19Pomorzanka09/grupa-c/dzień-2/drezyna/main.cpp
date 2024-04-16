#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int p[m][2];
    for (int i=0; i<m; i++)
        scanf("%d %d", &p[i][0], &p[i][1]);

    for (int i=0; i<m; i++)
    {
        if (p[i][0] > p[i][1])
            swap(p[i][0], p[i][1]);
    }

    // sortowanie
    int minimal[2], taken[2];
    for (int i=0; i<m; i++)
    {
        minimal[0] = p[i][0];
        minimal[1] = p[i][1];
        for (int j=i+1; j<m; j++)
        {
            if (p[j][0]<minimal[0])
            {
                taken[0] = minimal[0];
                taken[1] = minimal[1];
                minimal[0] = p[j][0];
                minimal[1] = p[j][1];
                p[j][0] = taken[0];
                p[j][1] = taken[1];
            }
        }
        p[i][0] = minimal[0];
        p[i][1] = minimal[1];
    }
    // koniec sortowania

    int z[n][n];
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            z[i][j] = -1;
        }
    }

    z[0][0] = p[0][0];
    z[0][1] = p[0][1];
    int c = -1, cc;
    bool e[2];
    for (int i=1; i<m; i++)
    {
        c = -1;
        e[0] = false;
        e[1] = false;
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                if (p[i][0] == z[j][k])
                {
                    c = j;
                    cc = k;
                    e[0] = true;
                }
                if (p[i][1] == z[j][k])
                {
                    c = j;
                    cc = k;
                    e[1] = true;
                }

            }

        }
        if (c != -1)
        {
            for (int j=0; j<n; j++)
            {
                if (z[c][j] == p[i][0] && z[c][j] == p[i][1])
                {
                    break;
                }
                /*else if (z[c][j] == p[i][0] || z[c][j] == p[i][1])
                {
                    cc = j;
                }*/
                if (z[c][j] == -1 && e[0] == false)
                {
                    z[c][j] = p[i][0];
                    e[0] = true;
                }
                if (z[c][j] == -1 && e[1] == false)
                {
                    z[c][j] = p[i][1];
                    e[1] = true;
                }
            }

        }
        else
        {
            for (int j=0; j<n; j++)
            {
                if (z[j][0] == -1)
                {
                    c = j;
                    break;
                }
            }
            z[c][0] = p[i][0];
            z[c][1] = p[i][1];
        }
    }

    // pocz¹tek pytan
    int q;
    scanf("%d", &q);
    int qq[q][2], r[q];
    bool t[q][2];
    for (int i=0; i<q; i++)
    {
        scanf("%d %d", &qq[i][0], &qq[i][1]);
    }
    for (int h=0; h<q; h++)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (z[i][j] == qq[h][0])
                    t[h][0] = true;
                if (z[i][j] == qq[h][1])
                    t[h][1] = true;
            }
        }
        if (t[h][0] == true && t[h][1] == true)
            r[h] = 1;
        else
            r[h] = 0;
    }

    for (int i=0; i<q; i++)
    {
        printf("%d", r[i]);
    }

    /*cout<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<z[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i=0; i<m; i++)
    {
        cout<<p[i][0]<<" "<<p[i][1]<<endl;
    }*/

    return 0;
}
