// Jakub Daszkiewicz
// zadanie Bitmapa
//
// test 1: 3 4 0001 0011 0110 => 3 2 1 0 2 1 0 0 1 0 0 1

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> white[2];

int find_closest(int x, int y)
{
    int r = 1000000;
    int d;
    for (int i=0; i<white[0].size(); i++)
    {
        d = abs(x-white[1][i])+abs(y-white[0][i]);
        if (d < r) r = d;
    }
    return r;
}

int main()
{
    unsigned int n, m;
    scanf("%u%u", &n, &m);
    getchar();
    char t;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            t = getchar();
            if (t == '1')
            {
                white[0].push_back(i);
                white[1].push_back(j);
            }
        }
        getchar();
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            printf("%d ", find_closest(j, i));
        }
        printf("\n");
    }
    return 0;
}