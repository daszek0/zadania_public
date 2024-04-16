#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d[3], m[3], r[3];
    for (int i=0; i<3; i++)
    {
        scanf("%d %d", &d[i], &m[i]);
    }
    int maximal = 0, maximalindex = -1;
    bool used[3];
    for (int i=0; i<3; i++)
        used[i] = false;
    for (int h=0; h<3; h++)
    {
        for (int i=0; i<3; i++)
        {
            if (d[i] > maximal && used[i] == false)
            {
                if (maximalindex > -1)
                    used[maximalindex] = false;
                maximal = d[i];
                maximalindex = i;
                used[i] = true;
            }
            else if (d[i] == maximal && used[i] == false)
            {
                if (m[i] > m[maximalindex])
                {
                    used[maximalindex] = false;
                    maximalindex = i;
                    used[i] = true;
                }
            }
        }

        r[h] = maximalindex;
        used[maximalindex] = true;
        maximal = 0;
        maximalindex = -1;
    }

    printf("%d", r[0]+1);
    for (int i=1; i<3; i++)
    {
        printf(" %d", r[i]+1);
    }

    return 0;
}
