// Jakub Daszkiewicz
// zadanie Zawody

// test 1: 4 3 26 2 39 3 45 1 56 2 => 2

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unsigned short int k, n;
    scanf("%hu %hu", &k, &n);
    unsigned int t[k], p[k];
    for (int i=0; i<k; i++)
    {
        scanf("%u %u", &t[i], &p[i]);
    }
    unsigned int tl;
    unsigned int s;
    vector<unsigned int> times;
    for (int i=0; i<k; i++)
    {
        tl = t[i];
        s = tl;
        times.push_back(s);
        for (int j=1; j<n; j++)
        {
            if (j % p[i] == 0)
            {
                tl = t[i];
            }
            else
            {
                tl++;
            }
            s += tl;
            times.push_back(s);
        }
    }
    sort(times.begin(), times.end());
    unsigned int m = 1, counter = 1;
    for(int i=1; i<times.size(); i++)
    {
        if (times[i] == times[i-1]) counter++;
        else counter = 1;
        if (counter > m) m = counter; // m = max(count, m);
    }
    printf("%u", m);
    return 0;
}