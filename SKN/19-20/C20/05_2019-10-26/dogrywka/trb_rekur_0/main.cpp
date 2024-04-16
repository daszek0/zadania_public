#include <stdio.h>

using namespace std;

int x[20000], temp, maximal = 0;

bool checktriangle()
{
    int triangle[3], t = 0;
    for (int i=0; i<3; i++) triangle[i] = 0;
    for (int i=maximal; i>=0; --i)
    {
        while (x[i] > 0)
        {
            triangle[t] = i;
            ++t;
            --x[i];
            if (t >= 3) break;
        }
        if (t >= 3) break;
    }
    if (triangle[2] == 0)
        return false;
    if (triangle[0]+triangle[1] > triangle[2] && triangle[2]+triangle[1] > triangle[0] && triangle[0]+triangle[2] > triangle[1])
        return true;
    else
    {
        ++x[triangle[1]];
        maximal = triangle[1];
        ++x[triangle[2]];
        return checktriangle();
    }
}

int main()
{
    int n;
    while (true)
    {
        scanf("%d", &n);
        if (n > 18)
        {
            printf("TAK\n");
            continue;
        }
        if (n == 0) break;
        for (int i=0; i<20000; i++) x[i] = 0;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &temp);
            x[temp]++;
            if (temp > maximal) maximal = temp;
        }
        if (checktriangle())
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}
