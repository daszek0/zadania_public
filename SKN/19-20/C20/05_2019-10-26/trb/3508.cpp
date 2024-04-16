#include <stdio.h>
using namespace std;
int main()
{
    int n;
    int x[20000], temp, maximal = 0;
    while (true)
    {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i=0; i<20000; i++) x[i] = 0;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &temp);
            x[temp]++;
            if (temp > maximal) maximal = temp;
        }
        bool r, a = false;
        do
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
            {
                r = false;
                a = false;
                break;
            }
            if (triangle[0]+triangle[1] > triangle[2] && triangle[2]+triangle[1] > triangle[0] && triangle[0]+triangle[2] > triangle[1])
            {
                r = true;
                a = false;
            }
            else
            {
                a = true;
                ++x[triangle[1]];
                maximal = triangle[1];
                ++x[triangle[2]];
            }
        } while (a == true);
        if (r)
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}
