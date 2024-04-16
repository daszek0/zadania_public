// Jakub Daszkiewicz
// zadanie ZAWODY

// test 1: 4 3 26 2 39 3 45 1 56 2 => 2

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unsigned short k, n;
    scanf("%hu %hu", &k, &n);
    unsigned int t;
    unsigned short p;
    unsigned int tl;
    unsigned long s;
    vector<unsigned long> ss;
    ss.reserve(10000001);
    for (unsigned short i=0; i<k; i++)
    {
        scanf("%u %hu", &t, &p);
        tl = t;
        s = tl;
        ss.push_back(s);
        for (unsigned short j=1; j<n; j++)
        {
            if (j%p == 0) tl = t;
            else tl++;
            s += tl;
            ss.push_back(s);
        }
    }
    ss.shrink_to_fit();
    sort(ss.begin(), ss.end());
    unsigned long m = 1, c = 1;
    for (unsigned long i=1; i<ss.size(); i++)
    {
        if (ss[i] == ss[i-1]) c++;
        else c = 1;
        m = max(m, c);
    }
    printf("%lu", m);
    return 0;
}