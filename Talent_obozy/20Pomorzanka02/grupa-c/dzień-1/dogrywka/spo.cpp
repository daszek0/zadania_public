// Jakub Daszkiewicz
// zadanie Sponsor

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// int tab_max(int tab[], int start, int end)
// {
//     int r = 0;
//     for (int i=start; i<end; i++)
//     {
//         r = max(r, tab[i]);
//     }
//     return r;
// }

int main()
{
    vector<double> t;
    double temp;
    while (true)
    {
        scanf("%lf", &temp);
        if (temp == 0) break;
        t.push_back(temp);
    }
    int r[t.size()];
    for (int i=0; i<t.size(); i++)
    {
        r[i] = 1;
    }
    for (int i=1; i<t.size(); i++)
    {
        for (int j=0; j<i; j++)
        {
            if (t[j] < t[i])
            {
                
            }

        }
    }
    return 0;
}