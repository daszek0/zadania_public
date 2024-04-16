// Jakub Daszkiewicz
// zadanie Sponsor

// test: 23.600 23.400 22.610 24.420 22.400 22.220 21.800 22.800 20.800 0 => 700

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

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
    vector<int> sp;
    sp.push_back(0);
    for (int i=1; i<t.size(); i++)
    {
        if (t[i] > t[i-1]) sp.push_back(i);
    }
    int rt = 100, r = 100;
    double check;
    for (int i=0; i<sp.size(); i++)
    {
        check = t[sp[i]];
        for (int ii=sp[i]+1; ii<t.size(); ii++)
        {
            if (t[ii] < check)
            {
                rt += 100;
                check = t[ii];
            }
        }
        r = max(rt, r);
        rt = 100;
    }
    printf("%d", r);
    return 0;
}