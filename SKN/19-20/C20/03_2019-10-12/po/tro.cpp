#include <stdio.h>
#include <vector>

using namespace std;

int p, q, n;
bool wagon[360000], ready;
vector <int> operacja[3];

int main()
{
    scanf("%d %d %d", &p, &q, &n);
    if (p > q)
    {
        int t = p;
        p = q;
        q = t;
    }
    int i = 0, o = 0;
    do
    {
        if (!wagon[i] && !wagon[i+p+q])
        {
            if (!wagon[i+p])
            {
                wagon[i] = 1;
                wagon[i+p] = 1;
                wagon[i+p+q] = 1;
                operacja[0].push_back(i);
                operacja[1].push_back(i+p);
                operacja[2].push_back(i+p+q);
                ++o;
            }
            else if (!wagon[i+q])
            {
                wagon[i] = 1;
                wagon[i+q] = 1;
                wagon[i+p+q] = 1;
                operacja[0].push_back(i);
                operacja[1].push_back(i+q);
                operacja[2].push_back(i+p+q);
                ++o;
            }
        }
        ++i;
        ready = true;
        for (int j=n-1; j>=0; j--)
        {
            if (!wagon[j])
            {
                ready = false;
                break;
            }
        }
    } while (!ready);

    printf("%d\n", o);
    for (int j=0; j<o; j++)
    {
        printf("%d %d %d\n", operacja[0][j]+1, operacja[1][j]+1, operacja[2][j]+1);
    }
    return 0;
}
