// Jakub Daszkiewicz
// zadanie Tarasy
//
// test 1: 5 1 4 2 1 2 4 => 4

#include <stdio.h>
#include <algorithm>

using namespace std;

int sum(int tab[], int begin, int end)
{
    int r = 0;
    if (begin != end)
    {
        for (int i=begin; i<end; i++)
        {
            if (tab[i] < tab[i+1]) r += tab[i+1]-tab[i];
        }
    }
    return r;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int h[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &h[i]);
    }
    int begin, end, v, cost, r_begin, r_end;
    begin = 0; end = 0; cost = 0; r_begin = 0;
    while (begin < n && end < n)
    {
        v = sum(h, begin, end);
        if (v <= k)
        {
            if (v > cost)
            {
                cost = v;
                r_begin = end-begin+1;
            }
            end++;
        }
        else
        {
            if (begin < end) begin++;
            else if (begin == end)
            {
                begin++;
                end++;
            }
        }
    }
    reverse(h, h+n);
    begin = 0; end = 0; cost = 0; r_end = 0;
    while (begin < n && end < n)
    {
        v = sum(h, begin, end);
        if (v <= k)
        {
            if (v > cost)
            {
                cost = v;
                r_end = end-begin+1;
            }
            end++;
        }
        else
        {
            if (begin < end) begin++;
            else if (begin == end)
            {
                begin++;
                end++;
            }
        }
    }
    printf("%d", max(r_begin, r_end));
    return 0;
}