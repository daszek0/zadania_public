// Jakub Daszkiewicz
// zadanie Leśne okręgi

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <long long> x, y;
    long long xt, yt;
    for (int i=0; i<n; i++)
    {
        scanf("%lld %lld", &xt, &yt);
        if (xt)
        {
            x.push_back(xt);
        }
        else
        {
            y.push_back(yt);
        }
    }
    unordered_map <long long, int> xm;
    // unordered_map <long long, int> ym;
    long long a = 0;
    for (unsigned i=0; i<x.size(); i++)
    {
        for (unsigned j=i+1; j<x.size(); j++)
        {
            xm[x[i] * x[j]]++;
        }
    }
    for (unsigned i=0; i<y.size(); i++)
    {
        for (unsigned j=i+1; j<y.size(); j++)
        {
            a += xm[y[i] * y[j]];
            // ym[y[i] * y[j]]++;
        }
    }
    // for (auto I: xm)
    // {
    //     a += I.second * ym[I.first];
    // }
    printf("%lld", a);
    return 0;
}